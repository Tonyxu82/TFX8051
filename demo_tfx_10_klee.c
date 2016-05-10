#include "tfx_test.h"
#include "emu8051.h"
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
// #include "klee.h"

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


test* cur_test = NULL;
core_8051* cur_core = NULL;

#define TFX_P0 (REG_P0+0x80)
#define TFX_P1 (REG_P1+0x80)
#define TFX_P2 (REG_P2+0x80)
#define TFX_P3 (REG_P3+0x80)


int getP(int aRegister){

    int p = 0;
    if(aRegister == TFX_P0){
        p=0;
    }else if(aRegister == TFX_P1){
        p=1;
    }else if(aRegister == TFX_P2){
        p=2;
    }else if(aRegister == TFX_P3){
        p=3;
    }else{
        p=-1;
    }

    return p;
}

int tfx_sfrread(core_8051* core, int aRegister){

    
    int outputbye = -1;

    if(aRegister == TFX_P0 ||
       aRegister == TFX_P1 ||
       aRegister == TFX_P2 ||
       aRegister == TFX_P3){

	    int p = getP(aRegister);

	    if(p == -1) goto sfrr_exception;
	    if(cur_test->in_cur_loc[p] >= cur_test->in_size[p])
	        goto sfrr_exception;
	    outputbye = cur_test->in[p][cur_test->in_cur_loc[p]++];
	    printf("SFRREAD %X FROM %X\n", outputbye, aRegister);
	    return outputbye;
	}

	return core->mSFR[aRegister - 0x80];

sfrr_exception:
    return 0;

}

void tfx_sfrwrite(core_8051* core, int aRegister){


    if(aRegister == TFX_P0 ||
       aRegister == TFX_P1 ||
       aRegister == TFX_P2 ||
       aRegister == TFX_P3){

	    int p = getP(aRegister);
	    if(p == -1) goto sfrw_exception;
	    if(cur_test->out_cur_loc[p] >= cur_test->out_size[p])
	        goto sfrw_exception;

	    cur_test->out[p][cur_test->out_cur_loc[p]++] = core->mSFR[aRegister-0x80];
	    printf("SFRWRITE %X TO %X\n", core->mSFR[aRegister-0x80], aRegister);
	}

sfrw_exception:
    return;

}

void tfx_exception(core_8051* core, int err_code)
{

    switch (err_code)
    {
    case EXCEPTION_IRET_SP_MISMATCH:
        if (opt_exception_iret_sp) return;
        break;
    case EXCEPTION_IRET_ACC_MISMATCH:
        if (opt_exception_iret_acc) return;
        break;
    case EXCEPTION_IRET_PSW_MISMATCH:
        if (opt_exception_iret_psw) return;
        break;
    case EXCEPTION_ACC_TO_A:
        if (!opt_exception_acc_to_a) return;
        break;
    case EXCEPTION_STACK:
        if (!opt_exception_stack) return;
        break;
    case EXCEPTION_ILLEGAL_OPCODE:
        if (!opt_exception_invalid) return;
        break;
    }
}


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
}



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
            	//can do sth
            	// if(old_pc != cur_core->mPC)
            	// 	printf("PC=%x\n", old_pc);
            }

		}
		while(targettime > getTick() && 
			   targetclocks > 0);

        while(targettime > getTick())
        {
            core_sleep(1);
        }

	}while(cur_test->out_cur_loc[2]<10);	

	//We can use a eval(expr) for the condition of ending this loop;

	return 0;
}


//====================================================================================

int before(){
	cur_core = create_core();
	return 0;
}

int after(){
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

byte klee_byte(const char* name){
	byte x;
	klee_make_symbolic(&x, sizeof x, name);
	return x;
}

int run_test(){
	printf("Run Test ...\n");

	int i = 0;
	int n = 10;

	cur_test = init_test(n, n);

	if(!cur_test) return -1;

	unsigned char *a = (unsigned char*)malloc(n);
	klee_make_symbolic(a, 10, "P0");


	for(i=0; i<n; i++){
		klee_assume(a[i]>0);
		klee_assume(a[i]<20);
	}

	for(i=0; i<n; i++){
		cur_test->in[0][i] = a[i];
	}

	// cur_test->in[0][0] = 1;
	// cur_test->in[0][1] = 1;
	// cur_test->in[0][2] = 7;
	// cur_test->in[0][3] = 6;
	// cur_test->in[0][4] = 5;
	// cur_test->in[0][5] = 4;
	// cur_test->in[0][6] = 3;
	// cur_test->in[0][7] = 2;
	// cur_test->in[0][8] = 1;
	// cur_test->in[0][9] = 0;

	// cur_test->in[0][0] = 1;
	// cur_test->in[0][1] = 1;
	// cur_test->in[0][2] = 1;
	// cur_test->in[0][3] = 8;
	// cur_test->in[0][4] = 1;
	// cur_test->in[0][5] = 1;
	// cur_test->in[0][6] = 1;
	// cur_test->in[0][7] = 1;
	// cur_test->in[0][8] = 3;
	// cur_test->in[0][9] = 1;

	printf("Run Core ...\n");
	run_core();

	printf("P2:");
	for(i = 0; i<n; i++){
		printf("%X ", cur_test->out[2][i]);
	}

	printf("\n");
	//free(a);

	return 0;
}


int main(int argc, char** argv){
	
	// if(argc < 2){
	// 	printf("Usage: ut_test fw\n");
	// 	return -1;
	// }
	
	/*
		According Hoare Triple {P}S{Q}
		P: Precondition  - before()
		S: Statements    - run_test()
		Q: Postcondition - after()

	*/

	before();

	if(load_obj(cur_core, "sort.hex")) return -1;

	run_test();
	
	after();

	return 0;
}
