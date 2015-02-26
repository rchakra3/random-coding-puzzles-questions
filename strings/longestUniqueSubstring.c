#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//check for longest unique substring

int main(int argc,char *argv[])
{
	int lastIndex[256];
	char *string=argv[1];
	int iter=0,startIndex=0,endIndex=0,location,windowStart=0,currlen=0,maxlength=0;

	for(iter=0;iter<256;iter++)
		lastIndex[iter]=-1;

	iter=0;
	while(windowStart<strlen(string))
	{
		location=string[iter]%256;

		if(lastIndex[location]!=-1)
		{
			
			currlen=iter-windowStart;

			if((iter-lastIndex[location])==0)
			{
				iter++;

				//iter is out of bounds
				if(iter>=strlen(string))
				{
					//check is there is a possibility of a longer substring when we move windowStart forward
					if(currlen-1 <=maxlength)
						break;

					windowStart++;
					iter=windowStart+1;

				}
				continue;
			}

			

			if(currlen>maxlength)
			{
				startIndex=windowStart;
				endIndex=iter-1;
				maxlength=currlen;
				
			}
			lastIndex[location]=iter;
			iter=++windowStart;
			
		}
		else
		{
			//printf("%c has never been seen before.\n",string[iter]);
			lastIndex[location]=iter;
			iter++;
			//iter is out of bounds
				if(iter>=strlen(string))
				{
					currlen=iter-windowStart;

					if(currlen>maxlength)
					{
						maxlength=currlen;
						startIndex=windowStart;
						endIndex=iter-1;
					}

					windowStart++;
					iter=windowStart+1;

				}
		}

	}

	printf("\nLongest unique substring:");
	for(iter=0;iter<maxlength;iter++)
	{
		printf("%c",string[startIndex+iter]);
	}
	printf("\n");
}