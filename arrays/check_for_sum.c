#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

void sort(int array[],int n){

	merge_sort(array,0,n-1);

}
// A utility function to print an array
void printArray(int arr[], int n)
{
	int i;
    for ( i = 0; i < n; i++)
        printf("%4d ", arr[i]);
}

void find_pairs(int array[],int n,int sum){

	sort(array,n);

	int i=0;
	int j=n-1;
	int curr_sum;

	while(i<j){

		curr_sum=array[i]+array[j];

		if(sum==curr_sum){
			printf("Pair: %d and %d\n",array[i],array[j]);
			i++;
			j--;
		}
			

		else if(sum<curr_sum){
			j--;
		}
		else{
			i++;
		}
	}
}


int main()
{
    int A[] = {1, 4, 45, 12, 6, 10, -8,7,};
    int n = 16;
    int arr_size = 7;
    
 	find_pairs(A, arr_size, n);
 	//printArray(A,7);
 	printf("\n");
    return 0;
}