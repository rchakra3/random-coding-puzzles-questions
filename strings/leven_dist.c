#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b,c) a<b?((a<c)?a:c):((b<c)?b:c)

void find_leven(char *string1,int n1,char *string2,int n2){

	int matrix[n1+1][n2+1];

	int i=0,j=0;
	int cost=1;

	for(i=0;i<=n1;i++)
		matrix[i][0]=i;

	for(j=0;j<=n2;j++)
		matrix[0][j]=j;

	for(i=1;i<=n1;i++){

		for(j=1;j<=n2;j++){
			if(string1[i]==string2[j]){
				cost=0;
			}
			else
				cost=1;

			matrix[i][j]=MIN(matrix[i][j-1] +1//equivalent to cost of deleting char from first, and inserting the character from second
							,matrix[i-1][j]+1//equivalent to deleting char from second, and inserting char from first
							,matrix[i-1][j-1]+cost//equivalent to cost of swapping
							);
		}
	}
	printf("The distance is %d",matrix[n1][n2]);
}


int main(int argc, char *argv[])
{
	char *string1=argv[1];
	char *string2=argv[2];
	printf("5,4,3:%d\n",MIN(4,3,5));
	find_leven(string1,strlen(string1),string2,strlen(string2));
	printf("\n");
}