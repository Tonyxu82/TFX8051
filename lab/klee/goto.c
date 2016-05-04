#include "klee.h"

int main(){
	int i = 0;
	klee_make_symbolic(&i, sizeof(i), "i");
	klee_assume(i<100);
	klee_assume(i>-100);
	//klee_prefer_cex(&i, i<100 && i>-100);

begin:
	if(i>10) goto end;
	i++;
	goto begin;

end:

	return 0;
}