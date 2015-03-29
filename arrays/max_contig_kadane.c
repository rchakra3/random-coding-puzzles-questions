#include <stdio.h>
#include <stdlib.h>


void kadane_with_neg_support(int array[],int n){

	int max_so_far=0;
	int max_ending_here=0;

	int i;

	for(i=0;i<n;i++){

		max_ending_here=max_ending_here+array[i];

		if(max_ending_here<0){
			max_ending_here=0;
		}
		else if(max_so_far<max_ending_here){
			max_so_far=max_ending_here;
		}

	}

	if(max_so_far==0){// all values <=0
		max_so_far=array[0];
		i=1;

		for(i=1;i<n;i++){

			if(max_so_far<array[i]){
				max_so_far=array[i];
			}
		}
	}

	printf("Max:%d\n",max_so_far);


}	

void kadane(int array[],int n){

	int max_so_far=0;

	int max_ending_here=0;

	int i;

	for(i=0;i<n;i++){

		max_ending_here=max_ending_here+array[i];

		if(max_ending_here<0){
			max_ending_here=0;
		}
		else if(max_so_far<max_ending_here){
			max_so_far=max_ending_here;
		}

	}

	printf("Max:%d\n",max_so_far);

}

int main(int argc, char *argv[]){

	int array[]={-2,-3,4,-1,-2,1,5,-3};

	kadane(array,(sizeof(array)/sizeof(int)));
	kadane_with_neg_support(array,(sizeof(array)/sizeof(int)));
}
