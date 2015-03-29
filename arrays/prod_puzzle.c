/*Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that 
prod[i] is equal to the product of all the elements of arr[] except arr[i]. 
Solve it without division operator and in O(n).*/
#include <stdio.h>
#include <stdlib.h>

void print_prod_array(int array[],int n){

	int array1[n];
	int i;
	array1[0]=1;

	for(i=1;i<n;i++){
		array1[i]=array1[i-1]*array[i-1];
	}
	int mult_so_far=1;
	for(i=n-2;i>=0;i--){
		mult_so_far*=array[i+1];
		array1[i]*=mult_so_far;
	}

	for(i=0;i<n;i++){
		printf("%d \n",array1[i]);
	}
}

int main(int argc, char *argv[]){

	int array[]={10,3,5,6,2};

	print_prod_array(array,sizeof(array)/sizeof(int));
}