
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

//bubble the first element to the right position
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



void insertion_sort(int array[],int n){

	int i,j,temp;

	for(i=1;i<n;i++){
		temp=array[i];
		j=i-1;
		while(array[j]>temp){
			array[j+1]=array[j];
			j--;
			if(j<0)
				break;
		}
		array[j+1]=temp;
	}
}

void bubble_sort(int array[],int n){

	int i,j;

	for(i=n-1;i>=0;i--){
		for(j=0;j<i;j++){
			if(array[j]>array[j+1])
				swap(&array[j],&array[j+1]);
		}
	}
}

int qs_partition(int array[],int start,int end){

	int pivot=array[end];

	int i=0;
	int j=end-1;

	while(i<j){
		while(array[i]<pivot){
			i++;
		}

		while(array[j]>pivot){
			j--;
		}
		if(i<j)
			swap(&array[i],&array[j]);
	}
	swap(&array[i],&array[end]);
	return i;

}


void quick_sort(int array[],int start,int end){

	if(start>end){
		return;
	}

	int partition=qs_partition(array,start,end);

	quick_sort(array,start,partition-1);
	quick_sort(array,partition+1,end);

}