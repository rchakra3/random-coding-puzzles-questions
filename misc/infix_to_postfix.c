#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "limits.h"
#include "GenericNode.h"
#include "stack.h"
//defining +,- to have prec 1, *,/ to have prec 2, ^ has prec 3
#define PREC(a) ((a=='+')||(a=='-'))?1:(a=='^'?3:2)
//returns 0 if not, else 1 for +,2 for -,3 for *,4 for /
#define IS_OPERATOR(a) (a=='+')?1:((a=='-')?2:(a=='*'?3:(a=='/'?4:(a=='^'?5:0))))


void infix_to_postfix(char *input){

	int len=strlen(input);
	int i=0;
	int op_id;
	StackNode *head=NULL;
	char c;
	char popped_c;
	char *output=(char*) malloc(sizeof(char)*len);
	strcpy(output,"");
	char *temp=(char*) malloc(sizeof(char)*2);
	temp[1]='\0';
	int check_stack_empty;

	while(i<len){

		c=input[i];
		op_id=IS_OPERATOR(input[i]);

		if(!op_id){

			if(c=='('){
				printf("%c pushed to stack\n",c);
				stack_push(&head,c);
			}
			else if(c==')'){
				popped_c=stack_pop(&head);
				while(popped_c!='('){
					temp[0]=popped_c;
					strcat(output,temp);
					popped_c=stack_pop(&head);
				}
			}
			else{//it should be a number

				if((c-'0') <10 && (c-'0')>0){
					temp[0]=c;
					strcat(output,temp);
				}
				else{
					printf("Invalid input\n");
					return;
				}

			}
		}

		else{// it is an operator

			check_stack_empty=stack_pop(&head);

			if(check_stack_empty==INT_MIN){
				printf("%c pushed to stack\n",c);
				stack_push(&head,c);
				i++;
				continue;
			}
			else{//safe character value
				popped_c=check_stack_empty;
			}

			if(popped_c=='('){
				stack_push(&head,popped_c);
				printf("%c pushed to stack\n",c);
				stack_push(&head,c);
				i++;
				continue;
			}
			/* I KNOW THE REDUNDANCY CAN BE REMOVED*/
			
			if(c=='^'){ //this is right associative
				while((PREC(c)) < (PREC(popped_c))){ //this only checks for left associative and so ^ fails
					//printf("PRECEDENCE of %c=%d is less than that of %c=%d\n",c,PREC(c),popped_c,PREC(popped_c));

					temp[0]=popped_c;
					strcat(output,temp);
					printf("%c popped from stack\n",popped_c);
					check_stack_empty=stack_pop(&head);
					if(check_stack_empty==INT_MIN){
						break;
					}
					popped_c=check_stack_empty;

					if(popped_c=='('){
						break;
					}

				}
			}

			else{ //left associative
				while((PREC(c)) <= (PREC(popped_c))){ //this only checks for left associative and so ^ fails
					//printf("PRECEDENCE of %c=%d is less than that of %c=%d\n",c,PREC(c),popped_c,PREC(popped_c));

					temp[0]=popped_c;
					strcat(output,temp);
					printf("%c popped from stack\n",popped_c);
					check_stack_empty=stack_pop(&head);
					if(check_stack_empty==INT_MIN){
						break;
					}
					popped_c=check_stack_empty;

					if(popped_c=='('){
						break;
					}

				}
			}
			if(check_stack_empty!=INT_MIN) //loop got over because of operator precedence rules, not because stack was empty
				stack_push(&head,popped_c);
			
			stack_push(&head,c);
			printf("%c pushed to stack\n",c);


		}
		i++;
		//printf("Value of i:%d, Value of len:%d\n",i,len);

	}
	check_stack_empty=stack_pop(&head);

	while(check_stack_empty!=INT_MIN){
		popped_c=check_stack_empty;
		temp[0]=popped_c;
		strcat(output,temp);
		//printf("Appending %s\n",temp);
		check_stack_empty=stack_pop(&head);
	}

	puts(output);


}

int main(int argc,char *argv[]){

	char *input=argv[1];

	printf("PREC of +:%d,PREC of *:%d,PREC of ^:%d\n",PREC('+'),PREC('*'),PREC('^'));

	infix_to_postfix(input);

}