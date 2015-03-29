#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

void print_union(int array1[],int array2[],int n,int m){

	merge_sort(array1,0,n-1);
	merge_sort(array2,0,m-1);

	int output_array[n+m];

	int i=0;
	int j=0;
	int k=0;

	while(i<n && j<m){
		
		if(array1[i]==array2[j]){
			output_array[k]=array2[j];
			i++;
			j++;
			k++;
		}

		else if(array1[i]<array2[j]){ //insert the smaller element and increment-need to keep track of duplicates
			output_array[k]=array1[i];
			i++;
			k++;
		}

		else{
			output_array[k]=array2[j];
			j++;
			k++;
		}
	}

	while(i<n){
		output_array[k]=array1[i];
		i++;
		k++;

	}
	while(j<m){
		output_array[k]=array2[j];
		j++;
		k++;
	}

	printf("\nUnion:\n");

	for(i=0;i<k;i++){
		printf("%d ",output_array[i]);
	}

}

void print_intersection(int array1[],int array2[],int n,int m){
	
	merge_sort(array1,0,n-1);
	merge_sort(array2,0,m-1);

	int output_array[n+m];

	int i=0;
	int j=0;
	int k=0;

	while(i<n && j<m){
		
		if(array1[i]==array2[j]){
			output_array[k]=array2[j];
			i++;
			j++;
			k++;
		}

		else if(array1[i]<array2[j]){
			i++;
		}

		else{
			j++;
		}
	}

	printf("\nIntersection:\n");

	for(i=0;i<k;i++){
		printf("%d ",output_array[i]);
	}

}


void print_exclusive_union(int array1[],int array2[],int n,int m){
	
	merge_sort(array1,0,n-1);
	merge_sort(array2,0,m-1);

	int output_array[n+m];

	int i=0;
	int j=0;
	int k=0;

	while(i<n && j<m){
		
		if(array1[i]==array2[j]){
			i++;
			j++;
		}

		else if(array1[i]<array2[j]){ //insert the smaller element and increment-need to keep track of duplicates
			output_array[k]=array1[i];
			i++;
			k++;
		}

		else{
			output_array[k]=array2[j];
			j++;
			k++;
		}
	}

	while(i<n){
		output_array[k]=array1[i];
		i++;
		k++;

	}
	while(j<m){
		output_array[k]=array2[j];
		j++;
		k++;
	}

	printf("\nExclusive union:\n");

	for(i=0;i<k;i++){
		printf("%d ",output_array[i]);
	}

}

int main(int argc, char *argv[]){

	int array1[]= {1, 2, 4, 5, 6};
	int array2[]= {2, 3, 5, 7};

	int size1=sizeof(array1) / sizeof(int);

	int size2=sizeof(array2) / sizeof(int);


	print_union(array1,array2,size1,size2);
	print_intersection(array1,array2,size1,size2);
	print_exclusive_union(array1,array2,size1,size2);

}
