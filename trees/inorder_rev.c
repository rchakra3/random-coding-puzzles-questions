#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack.h"

Node *insert(Node *root,int val)
{
	Node *newNode=NULL;

	if(root==NULL)
	{
		newNode=(Node*) malloc(sizeof(Node));

		newNode->value=val;
		newNode->left=NULL;
		newNode->right=NULL;
		//printf("Created new node:%d\n",newNode->value);
		return newNode;
	}

	else{

		if(root->value>=val)
		{
			root->left=insert(root->left,val);
			//printf("Node %d has a left child:%d\n",root->value,root->left->value);
		}
		else
		{
			root->right=insert(root->right,val);
			//printf("Node %d has a right child:%d\n",root->value,root->right->value);
		}
	}

	return root;

}

void find_sum(Node *head,int sum){

	Stack *s=(Stack*) malloc(sizeof(Stack));
	Stack *s2=(Stack*) malloc(sizeof(Stack));
	stack_initialize(s);
	stack_initialize(s2);
	Node *current=head;
	Node *current_right=head;
	int done=0;
	int curr_sum=0;

	do{
		while(current!=NULL){
			stack_push(s,current);
			current=current->left;
		}

		while(current_right!=NULL){
			stack_push(s2,current_right);
			current_right=current_right->right;
		}

		current=stack_pop(s);
		current_right=stack_pop(s2);

		//printf("Left:%d Right:%d\n",current->value,current_right->value);

		if(!current || !current_right){
			done =1;
		}
		else{
			//printf("%d ",current->value);
			curr_sum=current_right->value + current->value;
			if(curr_sum==sum){
				done=1;
				printf("Pair is %d and %d",current_right->value,current->value);
			}
			else if(curr_sum<sum){
				//push right back
				stack_push(s2,current_right);
				current_right=NULL;
				current=NULL;
			}
			else {
				//push left back
				stack_push(s,current);
				current=NULL;
				current_right=NULL;
			}
		}
		

	}while(!done);
	printf("\n");

}



void main(){
	Node *head1=NULL;
				
	head1=insert(head1,5);
	//print_inorder(head1);
	head1=insert(head1,3);
	//print_inorder(head1);
	head1=insert(head1,9);
	//print_inorder(head1);
	head1=insert(head1,1);
	//print_inorder(head1);
	head1=insert(head1,7);
	//print_inorder(head1);
	head1=insert(head1,11);

	find_sum(head1,14);
}