#include<stdio.h>
#include<stdlib.h>



int stringToNum(char *string)
{
	int multiplier=1,len=0,result,i=0;

	while(string[len]!='\0')
	{
		len++;
		multiplier*=10;
	}

	while(i<len)
	{
		multiplier/=10;
		result+=(string[i]-'0')*multiplier;
		i++;
	}

	return result;

}


int main(int argc,char *argv[])
{
	printf("Number:%d\n",stringToNum(argv[1]));	
}