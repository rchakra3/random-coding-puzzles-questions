#include <stdio.h>
#include <stdlib.h>


void printMSB(int num){

	printf("MSB: %d\n",((num&0x80000000)>>31));
}

void printBinary(int num){

	int count=0;

	while(count<32){

		printf("%d",(num&0x80000000)>>31);
		num<<=1;
		count++;
	}
	printf("\n");
}

int rightShift(int num,int count){

	printf("Right Shift by %d\n",count);
	return num>>count;
}

int leftShift(int num,int count){

	printf("Left Shift by %d\n",count);
	return num<<count;
}

void checkEndianness(){

	int a=1;
	char *b=&a;

	if(*b ){
		printf("Little endian");
	}
	else{
		printf("Big endian");
	}
}


int main(int argc, char *argv[]){

	//int num=atoi(argv[1]);

	//printMSB(num);
	//printBinary(num);
	//num=rightShift(num,1);
	//num=leftShift(num,1);
	//printBinary(num);
	checkEndianness();
}