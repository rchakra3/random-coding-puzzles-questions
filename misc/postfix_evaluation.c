#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GenericNode.h"
#include "stack.h"



//can be improved by changing input to contain spaces, assuming input is correct/verifying input
//this will allow multi digit numbers
//but the idea is the same
void evaluate_and_print_postfix(char *input){

	int len=strlen(input);
	char c;
	StackNode *head=NULL;

	int i=0;
	int current_val=0;
	int num1;
	int num2;

	while(i<len){
		c=input[i];
		current_val=0;
		if((c-'0') <10 && (c-'0')>0){
			stack_push(&head,(c-'0'));
		}
		else{
			num2=stack_pop(&head);
			num1=stack_pop(&head);

			if(c=='+'){
				current_val+=num1+num2;
			}
			else if(c=='-'){
				current_val+=num1-num2;
			}
			else if(c=='*'){
				current_val+=num1*num2;
			}
			else if(c=='/'){
				current_val+=num1/num2;
			}
			else{
				printf("Invalid expression\n");
				return;
			}

			stack_push(&head,current_val);

		}
		i++;
	}

	printf("The expression evaluates to %d\n",stack_pop(&head));

}

int main(int argc,char *argv[]){

	char *input= argv[1];

	evaluate_and_print_postfix(input);
}