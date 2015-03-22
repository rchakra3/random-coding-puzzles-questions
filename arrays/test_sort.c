#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

int main(int argc, char *argv[]){

	int array[]={9,8,7,6,5,4,3,2,1};

	//insertion_sort(array,(sizeof(array)/sizeof(int)));
	//bubble_sort(array,(sizeof(array)/sizeof(int)));
	quick_sort(array,0,(sizeof(array)/sizeof(int))-1);

	print_sub_Array(array,0,(sizeof(array)/sizeof(int))-1);
	printf("\n");

}
