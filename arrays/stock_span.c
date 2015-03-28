#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "GenericNode.h"
#include "stack.h"

/*prints the number of consecutive days preceeding current day where
stock price was lower or equal to current day*/

void print_stock_span(int stock_prices[],int n){

	int i=0;

	int popped_index;
	StackNode *head=NULL;
	int output_array[n];
	output_array[0]=0;
	stack_push(&head,i);
	i++;

	while(i<n){
		popped_index=stack_pop(&head);

		if(popped_index==INT_MIN){
			output_array[i]=i;
		}

		else if(stock_prices[i]<stock_prices[popped_index]){
			stack_push(&head,popped_index);
			output_array[i]=0;
		}

		else{
			while(stock_prices[i]>=stock_prices[popped_index]){

				popped_index=stack_pop(&head);

				if(popped_index==INT_MIN){
					break;
				}

			}
			if(popped_index==INT_MIN){
				output_array[i]=i;
			}

			else{
				stack_push(&head,popped_index);
				output_array[i]=i-popped_index-1;
			}
			
		}
		stack_push(&head,i);
		i++;

	}

	for(i=0;i<n;i++){
		printf("%d ",output_array[i]);
	}
}

int main(int argc, char *argv[]){

	int stock_prices[]={100,80,60,70,60,70,60,75,85};

	print_stock_span(stock_prices,sizeof(stock_prices)/sizeof(int));
}
