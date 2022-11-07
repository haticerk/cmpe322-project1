/* Specify the arguments, exec for the path */
struct numbers{
	int x;
	int y;
	char exec[256];
};

program PARTB_PROG{
	version PARTB_VERS{
		/* Takes a numbers structure and gives the integer result. */
		string partb(numbers)=1;
	}=1;
}=0x12345678;