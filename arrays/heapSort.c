#include <stdlib.h>
#include <stdio.h>

//*************************************DOES NOT WORK
int* heapify(int array[],int parent,int last)
{
		int temp=0;

		if(parent==5)
			return array;

		if((parent*2 +1)<last)
		if(array[parent*2 +1] > array[parent])
		{

			temp=array[parent*2 +1];
			array[parent*2 +1]=array[parent];
			array[parent]=temp;

			return heapify(array,parent*2 +1,last);
		}

		if((parent*2 +2)<last)
		if(array[parent*2 +2] > array[parent])
		{
			temp=array[parent*2 +2];
			array[parent*2 +2]=array[parent];
			array[parent]=temp;

			return heapify(array,parent*2 +2,last);
		}

		return array;
}


int* buildHeap(int array[])
{
	int parent=(6-2)/2,last=6,temp=0,i;
	int *returnArray;

	while(parent>=0)
	{
		printf("\nLast is now%d\n",last);
		returnArray=heapify(array,parent,last);
		temp=array[last-1];
		array[last-1]=array[0];
		array[0]=temp;
		last--;
		printf("\n");
		for(i=0;i<6;i++)
		{
			printf("%d ",array[i]);
		}
		printf("\n");


		parent--;
	}

	return array;
}

int main(int argc, char *argv[])
{
	int a[]={3,2,5,2,1,7};
	int *heap;
	int i=0;

	heap=buildHeap(a);
	printf("\n");
	for(i=0;i<6;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}


