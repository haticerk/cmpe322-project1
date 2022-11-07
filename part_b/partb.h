/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _PARTB_H_RPCGEN
#define _PARTB_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct numbers {
	int x;
	int y;
	char exec[256];
};
typedef struct numbers numbers;

#define PARTB_PROG 0x12345678
#define PARTB_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define partb 1
extern  char ** partb_1(numbers *, CLIENT *);
extern  char ** partb_1_svc(numbers *, struct svc_req *);
extern int partb_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define partb 1
extern  char ** partb_1();
extern  char ** partb_1_svc();
extern int partb_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_numbers (XDR *, numbers*);

#else /* K&R C */
extern bool_t xdr_numbers ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_PARTB_H_RPCGEN */