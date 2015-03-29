#include <stdio.h>
#include <stdlib.h>

void print_dups(int array[],int size,int range_max){

	int i=0;

	while(i<size){

		if(array[abs(array[i])]<0){
			printf("%d ",abs(array[i]));
		}
		else{
			array[abs(array[i])]=-array[abs(array[i])];
		}
		i++;
	}
}

int main(int argc, char *argv[]){

	int array[]= {1,2,2,3,3,5,6};

	int size=sizeof(array) / sizeof(int);

	int range_max=6;//i.e. the range of numbers is from 0 to 6

	print_dups(array,size,range_max);
}
