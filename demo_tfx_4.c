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

int eval();

int run_core(){
	int ticked = 1;
	
	do{
		int targettime = getTick()+10;
		unsigned int targetclocks = (opt_clock_hz / 1200);
		
		do{
			int old_pc = cur_core->mPC;
	       	targetclocks--;
            //clocks += 12;
            ticked = tick(cur_core);

            if(ticked){
            	//dumping trace here
            	if(enable_trace){
	            	fm.pc = old_pc;
	            	memcpy(fm.SFR, cur_core->mSFR, 128);
	            	memcpy(fm.LowerData, cur_core->mLowerData, 64);
	            	trace_record(&fm, trace);
            	}
            }
		}
		while(targettime > getTick() && 
			   targetclocks > 0);

        while(targettime > getTick())
        {
            core_sleep(1);
        }

	}while(eval());	

	//We can use a eval(expr) for the condition of ending this loop;

	return 0;
}


//====================================================================================
int eval(){
	if(cur_test->out_cur_loc[2]<4){
		return 1;
	}else{
		return 0;
	}
}

int before(){
	cur_core = create_core();
	if(enable_trace){
		trace = trace_new("sort4", cur_trace);
	}
	return 0;
}

int after(){
	if(enable_trace){
		trace_end(trace);
	}

	if(cur_test){
		delete_test(cur_test);
		cur_test = NULL;
	}

	if(cur_core){
		delete_core(cur_core);
		cur_core = NULL;
	}


	printf("Finish Test ...\n");
	return 0;

}

int run_test(){
	printf("Run Test ...\n");

	int i = 0;
	int n = 4;

	cur_test = init_test(n, n);

	if(!cur_test) return -1;

	for(i = 0; i<n; i++){
		cur_test->in[0][i] = n-i-1;
		cur_test->expect[2][i] = i;
	}

	run_core();

	int match = 1;

	for(i = 0; i<n; i++){
		if(cur_test->out[2][i] != cur_test->expect[2][i]){
			match = 0;
		}
	}

	if(match){
		printf(ANSI_COLOR_GREEN  "Pass" ANSI_COLOR_RESET "\n");
	}else{
		printf(ANSI_COLOR_RED "Fail" ANSI_COLOR_RESET "\n");
	}
}


int main(int argc, char** argv){
	
	if(argc < 2){
		printf("Usage: ut_test fw\n");
		return -1;
	}
	
	/*
		According Hoare Triple {P}S{Q}
		P: Precondition  - before()
		S: Statements    - run_test()
		Q: Postcondition - after()

	*/

	before();

	if(load_obj(cur_core, argv[1])) return -1;

	run_test();
	
	after();



	return 0;
}
