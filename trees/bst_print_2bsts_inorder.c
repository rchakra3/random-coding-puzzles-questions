#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void print_inorder(Node *head){

	Stack *s=(Stack*) malloc(sizeof(Stack));
	stack_initialize(s);
	Node *current=head;
	int done=0;

	do{
		while(current!=NULL){
			stack_push(s,current);
			current=current->left;
		}

		current=stack_pop(s);

		if(!current){
			done =1;
		}
		else{
			printf("%d ",current->value);
			current=current->right;
		}
		

	}while(!done);
	printf("\n");

}

void print2bsts_inorder(Node *head1,Node *head2){

	Stack *s1=(Stack*) malloc(sizeof(Stack));
	stack_initialize(s1);
	Stack *s2=(Stack*) malloc(sizeof(Stack));
	stack_initialize(s2);
	Node *current1=head1;
	Node *current2=head2;
	int done=0;

	do{
		//printf("Iteration\n");
		while(current1!=NULL){
			stack_push(s1,current1);
			current1=current1->left;
			//printf("Success push\n");
		}
		//printf("Before second loop\n");
		while(current2!=NULL){
			stack_push(s2,current2);
			current2=current2->left;
		}

		current1=stack_pop(s1);
		current2=stack_pop(s2);

		if(!current1 || !current2)
			done=1;

		else{
		
			if(current1->value < current2->value){
				printf("%d ",current1->value);
				current1=current1->right;
				stack_push(s2,current2);
				current2=NULL;
			}
			else{
				printf("%d ",current2->value);
				current2=current2->right;
				stack_push(s1,current1);
				current1=NULL;
			}
		}
	

	}while(!done);

	//printf("\n");

	done=0;

	while(!done){
		while(current1!=NULL){
			stack_push(s1,current1);
			current1=current1->left;
		}
		current1=stack_pop(s1);
		if(!current1){
			done =1;
		}
		else{
			printf("%d ",current1->value);
			current1=current1->right;
		}
	}

	done=0;

	while(!done){
		while(current2!=NULL){
			stack_push(s2,current2);
			current2=current2->left;
		}
		current2=stack_pop(s2);
		if(!current2){
			done =1;
		}
		else{
			printf("%d ",current2->value);
			current2=current2->right;
		}
	}

	printf("\n");

}


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


int main(){

	Node *head1=NULL,*head2=NULL;

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
	//print_inorder(head1);
	head2=insert(head2,6);
	head2=insert(head2,4);
	head2=insert(head2,10);
	head2=insert(head2,2);
	head2=insert(head2,8);
	head2=insert(head2,12);

	print2bsts_inorder(head1,head2);
	//print_inorder(head1);
}