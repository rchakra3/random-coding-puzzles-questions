#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkUnique(char *array);
int checkForRepeat(char *string,int len);

void main(int argc, char *argv[])
{
	printf("%s\n",argv[1]);
	printf("%d\n",checkUnique(argv[1]));
}

int checkUnique(char *string)
{
	int len=strlen(string);

	checkForRepeat(string,len);
}

int checkForRepeat(char *string,int len)
{
	int i=0;
	int result=0;
	int temp_var=0;

	for(i=0;i<len;i++)
	{

		temp_var=result&(1<<(string[i]-'a'));

		if(temp_var>0)
			return 0;

		result=result|(1<<(string[i]-'a'));
	}
	return 1;
}