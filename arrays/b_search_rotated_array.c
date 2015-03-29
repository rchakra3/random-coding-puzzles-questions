#include <stdio.h>
#include <stdlib.h>
#define SIZEOF_INT_ARRAY(arr) ((sizeof(arr)/sizeof(int)))





int binary_search(int array[],int start,int end,int key){

	int mid=(start+end)/2;

	if(start>end){
		return -1;
	}

	if(array[mid]==key)
		return mid;

	if(array[mid]<key){
		return binary_search(array,mid+1,end,key);
	}
	else{
		return binary_search(array,start,mid,key);
	}
}

int rotate_binary_search(int array[],int start,int end,int key){
	

	if(start>end){
		return -1;
	}

	int mid=(start+end)/2;

	if(array[mid]==key)
		return mid;

	//Case 1: start to end is a sorted array

	if(array[start]<array[end]){
		return binary_search(array,start,end,key);
	}

	//Case 2: the mid element is the pivot and thus, the largest element
	if(array[mid]>array[mid-1] && array[mid]>array[mid+1]){

		if(key<array[start]){
			return binary_search(array,mid+1,end,key);
		}
		else{
			return binary_search(array,start,mid,key);
		}
	}

	//Case 3: the mid element is not the pivot.
	//the pivot does not lie on the left side
	if(array[start]<array[mid]){

		if(key>=array[start] && key <array[mid]){
			//do binary search in this region
			return binary_search(array,start,mid,key);
		}
		else{
			return rotate_binary_search(array,mid+1,end,key);
		}
	}

	else{ //the pivot lies on the left side

		if(key<array[start]){ //search on the right side
			return rotate_binary_search(array,mid+1,end,key);
		}
		return binary_search(array,start,mid,key);
	}

}


int main(int argc, char *argv[]){


	int array[]={3,4,5,6,7,1,2};
	//int array[]={1,2,3,4,5};

	int key=atoi(argv[1]);

	int index=rotate_binary_search(array,0,SIZEOF_INT_ARRAY(array)-1,key);

	printf("%d present at index:%d\n",key,index);

}
