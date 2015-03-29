/*Find the two repeating elements in a given array
You are given an array of n+2 elements. All elements of the array are in range 1 to n. 
And all elements occur once except two numbers which occur twice. Find the two repeating numbers.
*/

#include <stdio.h>
#include <stdlib.h>


void print_2_repeating(int array[],int n){

	int range_max=n-2;

	int i;

	int a_xor_b=0;

	for(i=1;i<=range_max;i++){
		a_xor_b^=i;
	}

	int xor_with_dups=0;

	for(i=0;i<n;i++){
		a_xor_b^=array[i];
	}

	//gives the first set bit from the right
	int mask=a_xor_b & ~(a_xor_b-1);

	int a=0;

	for(i=1;i<=range_max;i++){

		if((i&mask) !=0){
			a^=i;
		}	
	}

	for(i=0;i<n;i++){
		if((array[i] & mask) != 0){
			a^=array[i];
		}
	}

	int b=a_xor_b^a;

	printf("%d and %d\n",a,b);
}

int main(int argc, char *argv[])
{
	int array[]={1,2,2,3,4,5,6,6,7};

	print_2_repeating(array,sizeof(array)/sizeof(int));
}