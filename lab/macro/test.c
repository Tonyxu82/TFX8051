//http://www.cprogramming.com/tutorial/cpreprocessor.html

#include <stdio.h>

#define SWAP(a, b)  do { a ^= b; \
						 b ^= a; \
						 a ^= b; \
					   } while ( 0 )


int main(){

	int x = 10;
	int y = 5;
	int z = 4;

	printf("Before x=%d y=%d z=%d\n", x, y, z);
	// What happens now?
	if(x < 0)
	    SWAP(x, y);
	else
	    SWAP(x, z); 

	printf("After x=%d y=%d z=%d\n", x, y, z);

	return 0;
}