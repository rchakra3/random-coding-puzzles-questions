#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverseStringRecursive(char *string,int start,int end)
{
	char *part1,*part2,*result,*temp;
	int mid=0;

	result=(char*)malloc(sizeof(char)*(end-start+1));

	mid=(start+end)/2;

	if(start==end)
	{
		//printf("Before segfault.Start:%d\n",start);
		temp=(char*)malloc(sizeof(char)*2);
		temp[0]=string[start];
		temp[1]='\0';
		return temp;
	}

	part2=reverseStringRecursive(string,start,mid);
	part1=reverseStringRecursive(string,mid+1,end);

	strcat(result,part1);
	strcat(result,part2);
	
	result[end-start+1]='\0';
	return result;

	
}

char *reverseString(char *string)
{
	return reverseStringRecursive(string,0,strlen(string)-1);
}


void main(int argc, char *argv[])
{
	printf("%s\nReversed:%s\n",argv[1],reverseString(argv[1]));
}