#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) a>b?b:a
#define MAX(a,b) a>b?a:b
#define UP -1
#define LEFT -2
#define DIAG -3

void lc_subseq_dp(char *string1,int n1,char *string2,int n2){

	int matrix[n1+1][n2+1];
	int traversal[n1+1][n2+1];

	int i,j;

	for(i=0;i<=n1;i++){
		matrix[i][0]=0;
		traversal[i][0]=0;
	}

	for(j=0;j<=n2;j++){
		matrix[0][j]=0;
		traversal[0][j]=0;
	}

	for(i=1;i<=n1;i++){
		for(j=1;j<=n2;j++){

			if(string1[i-1] == string2[j-1]){
				matrix[i][j]=matrix[i-1][j-1] +1;
				traversal[i][j]=DIAG;

			}
			else{
				if(matrix[i-1][j]>matrix[i][j-1]){//left is larger
					matrix[i][j]=matrix[i-1][j];
					traversal[i][j]=LEFT;
				}
				else{
					matrix[i][j]=matrix[i][j-1];
					traversal[i][j]=UP;
				}

			}
		}
	}

	printf("Longest subsequence is of length:%d\n",matrix[n1][n2]);

	char *result=(char*) malloc(matrix[n1][n2]);
	char *buffer=(char*) malloc(matrix[n1][n2]);
	strcpy(result,"");
	char *temp=(char*) malloc(2);

	i=n1;
	j=n2;

	while(i>0 && j>0){
		if(traversal[i][j]==DIAG){
			temp[0]=string1[i-1];
			temp[1]='\0';
			strcpy(buffer,"");
			strcat(buffer,temp);
			strcat(buffer,result);
			strcpy(result,buffer);
			i--;
			j--;
		}
		else if(traversal[i][j]==UP){
			j--;
		}
		else if(traversal[i][j]==LEFT){
			i--;
		}
		else{
			break;
		}
	}
	free(buffer);
	free(temp);
	printf("Longest subsequence is %s\n",result);
	free(result);
}


void lc_substring_dp(char *string1,int n1,char *string2,int n2){

	int matrix[n1+1][n2+1];
	int max_length=0;
	int res_row=0;
	int res_col=0;

	int i,j;

	for(i=0;i<=n1;i++){
		matrix[i][0]=0;
	}

	for(j=0;j<=n2;j++){
		matrix[0][j]=0;
	}

	for(i=1;i<=n1;i++){
		for(j=1;j<=n2;j++){

			if(string1[i-1] == string2[j-1]){
				matrix[i][j]=matrix[i-1][j-1] +1;

				if(matrix[i][j]>max_length){
					max_length=matrix[i][j];
					res_row=i;
					res_col=j;
				}

			}
			else{
				matrix[i][j]=0;
			}

		}
	}

	printf("Length of maximum common substring:%d\n",max_length);
	char result[max_length+1];

	i=res_row-max_length;
	int res_pos=0;

	while(i<res_row){
		result[res_pos]=string1[i];
		i++;
		res_pos++;
	}
	result[res_pos]='\0';

	printf("Longest substring is %s\n",result);

}




int main(int argc,char *argv[]){

	char *string1=argv[1];
	char *string2=argv[2];

	lc_subseq_dp(string1,strlen(string1),string2,strlen(string2));

	/*lcs(string1,strlen(string1)-1,string2,strlen(string2)-1,result,max_size);

	printf("Longest subsequence:\n");
	puts(result);

	strcpy(result,"");

	printf("\nLongest substring:\n");

	lc_substring(string1,strlen(string1)-1,string2,strlen(string2)-1,result,max_size);
	puts(result);*/
}

