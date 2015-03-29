/*Sort an array of 0s, 1s and 2s
Given an array A[] consisting 0s, 1s and 2s, write a function that sorts A[]. The functions should put all 0s first, then all 1s and all 2s in last.

Example
Input = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
Output = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}
*/


#include <stdio.h>
#include <stdlib.h>

//pretty cool huh?!
void segregate_and_print(int array[],int n){

	int start=0;
	int mid=0;
	int end=n-1;

	while(mid<=end){

		if(array[mid]==0){
			//JUST BECAUSE
			array[mid]^=array[start];
			array[start]^=array[mid];
			array[mid]^=array[start];
			mid++;
			start++;
		}
		else if(array[mid]==1){
			//all good
			mid++;
		}
		else{
			array[mid]^=array[end];
			array[end]^=array[mid];
			array[mid]^=array[end];
			end--;
		}
	}

	for(start=0;start<n;start++){
		printf("%d ",array[start]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int array[]={0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};

	segregate_and_print(array,sizeof(array)/sizeof(int));
}