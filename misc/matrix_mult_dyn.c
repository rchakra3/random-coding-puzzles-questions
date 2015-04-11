#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>

int num_mult=0;
long **k_table;

long find_min_mult(long array[],long first_matrix,long last_matrix,long **d_table){

	long i=0,k;
	long min_val=INT_MAX,curr_val,max_val=INT_MIN;
	long j=0;
	long min_k=0;

	for(i=last_matrix-1;i>0;i--){

		for(j=i+1;j<=last_matrix;j++){

			min_val=INT_MAX;
			
			for(k=i;k<j;k++){
				curr_val=d_table[i][k]+d_table[k+1][j] + (array[i-1] * array[k] * array[j]);

				num_mult+=2;
			
				if(curr_val<min_val){
					min_val=curr_val;
					min_k=k;
				}

			}
			d_table[i][j]=min_val;
			k_table[i][j]=min_k;
		}
	}

	/*for(i=0;i<last_matrix+1;i++){
		for(j=0;j<last_matrix+1;j++){
			printf("%ld ",d_table[i][j]);
		}
		printf("\n");
	}

	printf("\nMin:%ld Max:%ld max/min:%ld",min_val,max_val,max_val/min_val);*/


	return d_table[first_matrix][last_matrix];

}

void print_k_table(int n){

	int i,j;

	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			printf("%ld ",k_table[i][j]);
		}
		printf("\n");
	}
}

char *print_optimal(long start,long end){

	if(start>end)
		return "";


	char *buffer=(char*) malloc(sizeof(char)*(end-start+100));

	if(start==end){
		strcpy(buffer,"");
		sprintf(buffer,"M%ld",start);
		return buffer;
	}


	strcpy(buffer,"(");
	strcat(buffer,print_optimal(start,k_table[start][end]));
	//printf("k:%ld\n",k_table[start][end]);
	strcat(buffer,"*");
	strcat(buffer,print_optimal(k_table[start][end]+1,end));
	strcat(buffer,")");

	//puts(buffer);

	return buffer;
}

long main(long argc, char *argv[]){

	long array_of_dimensions[argc-1];

	long i=1;

	while(i<argc){

		array_of_dimensions[i-1]=atoi(argv[i]);
		i++;
	}

	long **d_table;

	d_table=malloc(sizeof(long)*(argc-1)); //allocate space for the start of each row
	k_table=malloc(sizeof(long)*(argc-1));

	long iter=0;
	long j=0;
	for(iter=0;iter<=argc-2;iter++){
		d_table[iter]=malloc(sizeof(long)*(argc-1)); //allocate space for the cols in each row
		k_table[iter]=malloc(sizeof(long)*(argc-1));
		d_table[iter][iter]=0;
		k_table[iter][iter]=-1;
	}

	clock_t begin, end;
	double time_spent;

	begin = clock();

	printf("Minimum number of multiplications is %ld\n",find_min_mult(array_of_dimensions,1,(argc-2),d_table));
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Run time was %f milliseconds\n",time_spent*1000);
	printf("Number of scalar multiplications is: %d\n",num_mult);

	//print_k_table(argc-1);
	printf("The optimal placement of paranthesis is:\n");
	puts(print_optimal(1,argc-2));

}
