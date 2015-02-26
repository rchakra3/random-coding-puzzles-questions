#include <stdio.h>
#include <stdlib.h>

//O(n) time


int second_largest(int numbers[],int len)
{
	int max=0,second=0,i;

	for(i=0;i<len;i++)
	{
		if(numbers[i]>max)
		{
			second=max;
			max=numbers[i];
		}
		else if (numbers[i]>second && numbers[i]!=max)
		{
			second=numbers[i];
		}
	}

	return second;


}


int main(int argc, char *argv[])
{

	int numbers[argc],i=0;

	for(i=0;i<argc-1;i++)
	{
		numbers[i]=atoi(argv[i+1]);
	}

	printf("Second Largest: %d\n",second_largest(numbers,argc-1));

	return 1;
}