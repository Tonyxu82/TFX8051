/* Common
 * Copyright 2016 Lai Xu (Tony)
 *
 * Permission is hereby granted, free of charge, to any person obtaining 
 * a copy of this software and associated documentation files (the 
 * "Software"), to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, merge, publish, 
 * distribute, sublicense, and/or sell copies of the Software, and to 
 * permit persons to whom the Software is furnished to do so, subject 
 * to the following conditions: 
 *
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software. 
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE. 
 *
 * (i.e. the MIT License)
 *
 * tfx_coverage.c
 * 
 */

#include "tfx_coverage.h"

void begin_coverage(char* fw_name, core_8051* core){
	
	if(!core->mCodeCov) return;

	char cov_file[COV_FILE_NAME_SIZE];
	static_unit su;

	sprintf(cov_file, "%s.cov", fw_name);

	FILE* fp = fopen(cov_file, "rb");
	if(!fp) return;

	while(fread(&su, sizeof(static_unit), 1, fp)){
		core->mCodeCov[su.pc] = su.stat;
	}

	fclose(fp);
}

void end_coverage(char* fw_name, core_8051* core){
	char assembly[128];
	if(!core->mCodeCov) return;

	char cov_file[COV_FILE_NAME_SIZE];
	static_unit su;
	int pc_exe  =0;

	sprintf(cov_file, "%s.cov", fw_name);

	FILE* fp = fopen(cov_file, "wb");
	if(!fp) return;

	for(int i=0; i<core->mCodeMemSize; i++){
		if(core->mCodeCov[i] > 0){
			su.pc = i;
			su.stat = core->mCodeCov[i];
			fwrite(&su, sizeof(static_unit), 1, fp);

			pc_exe++;
		}
	}

	// if(core->mCodeCovTotalIns>0)
	// 	printf("Coverage:%d%%\n",pc_exe*100/core->mCodeCovTotalIns);
	// else
	// 	printf("Coverage Analyze Error\n");

}
