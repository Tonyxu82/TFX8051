//http://www.cprogramming.com/tutorial/cfileio.html

#include <stdio.h>
#include <string.h>

typedef unsigned char byte;

typedef struct frame frame;
struct frame{
	int pc;
	int addr1;
	byte data1;
	int addr2;
	byte data2;
	int addr3;
	byte data3;
};

class frame2{
public:
	int pc;
	int addr1;
	byte data1;
	int addr2;
	byte data2;
	int addr3;
	byte data3;

};

void print_frame(frame f){
	printf("%d %d %d %d %d %d %d\n",
			f.pc, f.addr1, f.data1,
			f.addr2, f.data2,
			f.addr3, f.data3);
}

int main(int argc, char** agrv){

	FILE* fp;
	fp = fopen("test.bin", "wb");
	
	frame f;
	f.pc = 1111;
	f.addr1 = 0x80;
	f.data1 = 0x01;
	f.addr2 = 0x90;
	f.data2 = 0x02;
	f.addr3 = 0xA0;
	f.data3 = 0x03;

	print_frame(f);

	fwrite(&f, sizeof(frame), 1, fp);
	fclose(fp);

	fp= fopen("test.bin", "rb");
	frame f1;
	memset(&f1, 0, sizeof(frame));

	fread(&f1, sizeof(frame), 1, fp);

	print_frame(f1);

	//Test read a byte from a binary file

	//Tset write a byte to a binary file
	fclose(fp);
	return 0;
}
