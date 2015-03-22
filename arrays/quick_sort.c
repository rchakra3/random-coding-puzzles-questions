#include <stdio.h>
#include <stdlib.h>


int partition(int arr[],int left,int right){

	int pivot=arr[right],temp,orig_right=right;
	right--;

	while(left<right){

			while(arr[left]<pivot){
				left++;
			}
			while(arr[right]>pivot){
				right--;
			}
			if(left<right){

				printf("Swapping %d and %d\n",arr[left],arr[right]);

				temp=arr[left];
				arr[left]=arr[right];
				arr[right]=temp;
			}
	}



	temp=arr[left];
	arr[left]=arr[orig_right];
	arr[orig_right]=temp;

	return left;

}

void printArray(int arr[], int n)
{
	int i;
    for ( i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void quick_sort(int arr[],int left,int right){

	int i=left,j=right;

	if(i>=j){
		return;
	}

	int pivot_index=partition(arr,left,right);
	printf("Single partition\n\n");
	printArray(arr, right+1);
	//quick_sort(arr,left,pivot_index-1);
	//quick_sort(arr,pivot_index+1,right);
}


int main()
{
    int arr[] = {-1, 2, -3, 9, 5, 6, -7, -8, 8, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Initial:\n");
	printArray(arr, n);
    quick_sort(arr,0,n-1);
    printArray(arr, n);
    
    return 0;
}