#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "GenericNode.h"
#include "stack.h"

void print_next_greater_array(int array[],int n){

	int i;
	int possible_next_greater;
	StackNode *head=NULL;
	int output_array[n];

	output_array[n-1]=-1;
	stack_push(&head,array[n-1]);

	for(i=n-2;i>=0;i--){

		possible_next_greater=stack_pop(&head);

		if(possible_next_greater==INT_MIN){
			output_array[i]=-1;
			stack_push(&head,array[i]);
		}
		else{
			if(possible_next_greater>array[i]){
				output_array[i]=possible_next_greater;
				stack_push(&head,possible_next_greater);
				stack_push(&head,array[i]);
			}
			else{
				//keep popping till there's a greater element

				while(possible_next_greater<=array[i]){
					possible_next_greater=stack_pop(&head);
					if(possible_next_greater==INT_MIN){//stack's empty. NO Greater element. push this
						output_array[i]=-1;
						stack_push(&head,array[i]);
						break;
					}
				}
				if(possible_next_greater!=INT_MIN){ //there is one
					output_array[i]=possible_next_greater;
					stack_push(&head,possible_next_greater);
					stack_push(&head,array[i]);
				}
			}
		}


	}


	for(i=0;i<n;i++){
		printf("%d ",output_array[i]);
	}
}

int main(int argc, char *argv[]){

	int array[]={13,7,6,12};

	print_next_greater_array(array,4);

}
