
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void bubble_to_place(int array[],int start,int end){

	if(start>=end)
		return;

	while(array[start]>array[start+1]){
			swap(&(array[start]),&(array[start+1]));
			start++;
			if(start>=end)
				break;
	}
}

// A utility function to print an array
void print_sub_Array(int arr[], int start,int end)
{
	int i;
    for ( i = start; i <= end; i++)
        printf("%4d ", arr[i]);

    
}

//in_place merge
void merge(int array[],int start1,int end1,int start2,int end2){

	int i=start1,j=start2;

	while(i<=end1 && j<=end2){

		if(array[i]>array[j]){
			swap(&array[i],&array[j]);
		}
		i++;
		//ensure second part remains sorted
		bubble_to_place(array,j,end2);
	}


}


void merge_sort(int array[],int start,int end){


	if(start==end){
		return;
	}

	int mid=(start+end)/2;

	merge_sort(array,start,mid);
	merge_sort(array,mid+1,end);

	merge(array,start,mid,mid+1,end);
}