#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#include "emu8051.h"
#include "tfx_io.h"
#include "tfx_test.h"
#include "tfx_trace.h"
#include "tfx_common.h"
#include "tfx_exception.h"

//Test
test*  cur_test = NULL;

//8051 Core
core_8051* cur_core = NULL;

//Trace
#define FILE_NAME_SIZE 50
int enable_trace = 1;
FILE* trace = NULL;
char cur_trace[FILE_NAME_SIZE];
frame fm;


int opt_exception_iret_sp = 1;
int opt_exception_iret_acc = 1;
int opt_exception_iret_psw = 1;
int opt_exception_acc_to_a = 1;
int opt_exception_stack = 1;
int opt_exception_invalid = 1;
int opt_input_outputlow = 1;
int opt_clock_select = 3;
int opt_clock_hz = 12*1000*1000;
int opt_step_instruction = 0;

int clockspeeds[] = { 
    33*1000*1000,
    24*1000*1000, 
    22*1000*1000, 
    12*1000*1000, 
    11*1000*1000, 
       73728*100,
     6*1000*1000,
     5*1000*1000,
       49152*100,
     3*1000*1000,
       1000*1000,
        100*1000
};

core_8051* create_core(){
	core_8051* core = (core_8051*)malloc(sizeof(core_8051));
	memset(core, 0, sizeof(core_8051));
    core->mCodeMem     = malloc(65536);
    core->mCodeMemSize = 65536;
    core->mExtData     = malloc(65536);
    core->mExtDataSize = 65536;
    core->mLowerData   = malloc(128);
    core->mUpperData   = malloc(128);
    core->mSFR         = malloc(128);
    core->except       = &tfx_exception;
    core->sfrread      = &tfx_sfrread;
    core->sfrwrite     = &tfx_sfrwrite;
    core->xread = NULL;
    core->xwrite = NULL;
    reset(core, 1);

    return core;
}

//free memory allocated to the core 8051
#define FREE_CORE_MEM(mem) { \
							  if(mem){ \
							  	free(mem); \
							  	mem = NULL; \
							  } \
						   }

void delete_core(core_8051* core){

	if(!core) return;

	FREE_CORE_MEM(core->mCodeMem);
	FREE_CORE_MEM(core->mExtData);
	FREE_CORE_MEM(core->mLowerData);
	FREE_CORE_MEM(core->mUpperData);
	FREE_CORE_MEM(core->mSFR);

	core = NULL;
}


int main(int argc, char** argv){
	
	if(argc < 3){
		printf("Usage: trace_reply firmware trace\n");
		return -1;
	}
	
    int i = 0;
    int n = 10;

    cur_test = init_test(n, n);

    unsigned char *a = (unsigned char*)malloc(n);
    klee_make_symbolic(a, 10, "P0");

    for(i=0; i<n; i++){
        klee_assume(a[i]>0);
        klee_assume(a[i]<20);
    }

    for(i=0; i<n; i++){
        cur_test->in[0][i] = a[i];
    }


	cur_core = create_core();
	if(!cur_core) return -1;

	if(load_obj(cur_core, argv[1])) return -1;

	trace_replay(argv[2], cur_core);

    printf("P2:");
    for(i = 0; i<n; i++){
        printf("%X ", cur_test->out[2][i]);
    }

    printf("\n");

	return 0;
}
