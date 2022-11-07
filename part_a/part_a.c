/**
 * @author Hatice Erk
 * 
 * I wrote and executed the code in gcc 10.2.1 in Kali Linux.
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]){

    //The necessary integers, ids, buffers.
    int p2b[2], b2pforerr[2], b2pforout[2];   
    pid_t pid;
    char writeBuffer[10000], readforerrBuffer[10000], readforoutBuffer[10000];
    FILE *file = fopen(argv[2], "a");
    
    //Implementation of pipes.
    pipe(p2b);
    pipe(b2pforerr);
    pipe(b2pforout);

    pid = fork();
    
    //If fork() is failed.
    if(pid == -1){
        fprintf(stderr, "fork() failed.\n");
        exit(-1);
    }

    //Parent Process
    if(pid > 0){
        close(p2b[0]);
        close(b2pforerr[1]);
        close(b2pforout[1]);

#ifndef RUN_EXEC

        //Reads from the console and then write to pipe p2b.
        int a;
        int b;
        scanf("%d %d", &a, &b);

        int errbytes = -1; 
        int outbytes = -1;
    
        sprintf(writeBuffer, "%d %d\n", a, b);
        write(p2b[1], writeBuffer, strlen(writeBuffer));

        //Parent reads from pipes if which is used, then writes to file.
        errbytes = read(b2pforerr[0], readforerrBuffer, sizeof(readforerrBuffer));
        outbytes = read(b2pforout[0], readforoutBuffer, sizeof(readforoutBuffer));

        if(outbytes > 0){
            fprintf(file, "SUCCESS:\n%s\n", readforoutBuffer);
        }else{
            fprintf(file, "FAIL:\n%s\n", readforerrBuffer);
        }
#endif 
    }
    //The Child process.
    else{
        dup2(p2b[0], STDIN_FILENO);
        dup2(b2pforout[1], STDOUT_FILENO);
        dup2(b2pforerr[1], STDERR_FILENO);

        close(b2pforerr[0]);
        close(b2pforerr[1]);
        close(b2pforout[0]);
        close(b2pforout[1]);
        close(p2b[0]);
        close(p2b[1]);

#ifndef RUN_EXEC
        //Takes input from pipe, then writes back to pipes b2pforerr or b2pfor out.
        int a;
        int b;
        execl(argv[1], NULL);
        scanf("%d %d", &a, &b);
#endif        

    }

    return(0);
}