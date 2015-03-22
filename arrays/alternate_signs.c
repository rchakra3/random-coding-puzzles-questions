#include <stdio.h>
#include <stdlib.h>
#define POS 1
#define NEG 0

// A utility function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// A utility function to print an array
void printArray(int arr[], int n)
{
	int i;
    for ( i = 0; i < n; i++)
        printf("%4d ", arr[i]);
}


void rearrange(int arr[],int n){

	int i=0,j=n-1;

	//set pivot at 0, split array into 2 around pivot
	int pivot=0;

	while(i<j){
		while(arr[i]<pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		if(i<j){
			swap(&arr[i],&arr[j]);
		}
	}

	int start_of_pos=i;

	i=0;j=start_of_pos;

	//Setting first element to positive
	while(i<j && j<n){

		if(i%2 ==0){
			swap(&arr[i],&arr[j]);
			i++;
			j++;
		}
		else{
			i++;
		}
	}

	//printArray(arr,n);

}


 
// Driver program to test above functions
int main()
{
    int arr[] = {1, -2, 3, -9, -5, -6, 7, -8, -4};
    int n = sizeof(arr)/sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
    
    return 0;
}