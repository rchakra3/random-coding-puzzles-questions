#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) a>b?b:a

int lc_substring(char *string1,int end1,char *string2,int end2,char *result,int max_size){

	if(end1<0||end2<0)
		return 0;

	char *buffer=(char*) malloc(max_size);
	char *buffer2=(char*) malloc(max_size);
	strcpy(buffer,"");
	strcpy(buffer2,"");
	char *temp=(char*) malloc(2);

	if(string1[end1]==string2[end2]){
		temp[0]=string1[end1];
		temp[1]='\0';

		strcpy(buffer,result);

		strcpy(result,temp);
		strcat(result,buffer);
		free(buffer);

		return 1+ lc_substring(string1,end1-1,string2,end2-1,result,max_size);
	}

	else{
		
		int orig_length=strlen(result);
		int length1=lc_substring(string1,end1-1,string2,end2,buffer,max_size);
		int length2=lc_substring(string1,end1,string2,end2-1,buffer2,max_size);

		if(orig_length>length1){
			free(buffer);

			if(orig_length>length2){
				free(buffer2);
				return orig_length;
			}
			else{
				strcpy(result,buffer2);
				free(buffer2);
				return length2;
			}
		}
		else{
			if(length1>length2){
				free(buffer2);
				strcpy(result,buffer);
				free(buffer);
				return length1;
			}
			else{
				free(buffer);
				strcpy(result,buffer2);
				free(buffer2);
				return length2;
			}
		}

	}
}

void lcs(char *string1,int end1,char *string2,int end2,char *result,int max_size){

	if(end1<0||end2<0)
		return;

	char *buffer=(char*) malloc(max_size);
	strcpy(buffer,result);
	char *temp=(char*) malloc(2);

	int length1=0,length2=0;

	if(string1[end1]==string2[end2]){
		temp[0]=string1[end1];
		temp[1]='\0';

		strcpy(result,temp);
		strcat(result,buffer);
		free(buffer);

		lcs(string1,end1-1,string2,end2-1,result,max_size);
	}

	else{

		lcs(string1,end1-1,string2,end2,buffer,max_size);
		lcs(string1,end1,string2,end2-1,result,max_size);

		length1=strlen(buffer);
		length2=strlen(result);

		if(length1<length2){
			//printf("%s was longer than %s\n",result,buffer);
			free(buffer);
		}
		else{
			//printf("%s was longer than %s\n",buffer,result);
			strcpy(result,buffer);
			free(buffer);
		}
	}

}

int main(int argc,char *argv[]){

	char *string1=argv[1];
	char *string2=argv[2];

	int max_size=MIN(strlen(string1),strlen(string2));

	char *buffer[strlen(string1)][strlen(string2)];

	char *result=(char*) malloc( max_size+ 1);
	strcpy(result,"");

	lcs(string1,strlen(string1)-1,string2,strlen(string2)-1,result,max_size);

	printf("Longest subsequence:\n");
	puts(result);

	strcpy(result,"");

	printf("\nLongest substring:\n");

	lc_substring(string1,strlen(string1)-1,string2,strlen(string2)-1,result,max_size);
	puts(result);
}