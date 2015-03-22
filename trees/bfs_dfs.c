#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "node_stack.h"
#include "queue.h"



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

void bfs(Node *head1){

	Queue *q=(Queue*) malloc(sizeof(Queue));

	queue_enqueue(&q,head1);

	Node *current=NULL;

	while((current=queue_dequeue(&q))!=NULL){

		printf("%d ",current->value);
		if(current->left!=NULL)
			queue_enqueue(&q,current->left);
		if(current->right!=NULL)
			queue_enqueue(&q,current->right);
	}
	
}

void dfs(Node *head){

	Node_Stack *stack=NULL;

	Stack_push(&stack,head);
	
	Node *current=NULL;

	while((current=Stack_pop(&stack))!=NULL){
		printf("%d ",current->value);
		if(current->right!=NULL)
			Stack_push(&stack,current->right);
		if(current->left!=NULL)
			Stack_push(&stack,current->left);
	}
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

	//bfs(head1);
	dfs(head1);
	//print_inorder(head1);
}