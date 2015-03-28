#include <stdio.h>
#include <stdlib.h>


typedef struct node{

	int value;
	struct node* next;
}Node;


Node * initList()
{
	int i=0;
	Node *prev,*node,*head;


	for(i=0;i<9;i++)
	{
		node=(Node*) malloc(sizeof(Node));

		node->value=i+1;

		if(prev==NULL)
		{
			head=prev=node;
			continue;
		}

		prev->next=node;
		prev=node;

	}


	return head;
}


void printRevRecursive(Node *head)
{
	if(head==NULL)
	{
		return;
	}

	printRevRecursive(head->next);
	printf("%d ", head->value);
}

Node * reverseList(Node *head){

	Node *prev=NULL;
	Node *current=head;
	Node *next;

	while(current!=NULL){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	return prev;
}

Node *reverse_k_from_head(Node *head,int k){ //returns the new head.

	Node *p = head;
	Node *q = p->next;

	if(q==NULL){ //there's just one node
		return head;
	}
	Node *r = q->next;

	int count=0;

	while(count<(k-1) && q!=NULL){

		q->next = p;

		p=q;
		q=r;

		if(r!=NULL)
			r=r->next;

		count++;
	}
	head->next=q;

	//*head = q;

	return p;
}

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

void reverse_every_k(Node **head,int k){

	Node *traverser= *head;
	Node *new_head=NULL;
	Node *prev_traverser=NULL;

	while(traverser!=NULL){

		new_head=reverse_k_from_head(traverser,k);
		
		if(prev_traverser!=NULL) // this is not the first iteration
			prev_traverser->next=new_head;

		else //this is the first iteration. change the head pointer.
			*head = new_head;
		
		prev_traverser=traverser;
		
		if(traverser!=NULL)
			traverser=traverser->next;
	
	}

}

void reverse_every_alternate_k(Node **head,int k){

	Node *traverser= *head;
	Node *new_head=NULL;
	Node *prev_traverser=NULL;

	int reverse_flag=1;
	int counter=0;

	while(traverser!=NULL){

		if(reverse_flag){
			new_head=reverse_k_from_head(traverser,k);
			
			if(prev_traverser!=NULL) // this is not the first iteration
				prev_traverser->next=new_head;

			else //this is the first iteration. change the head pointer.
				*head = new_head;
			
			prev_traverser=traverser;
			
			if(traverser!=NULL)
				traverser=traverser->next;

			reverse_flag=0;
		}
		else{
			counter=0;

			while(counter<k && traverser!=NULL){
				prev_traverser=traverser;
				traverser=traverser->next;
				counter++;
			}
			reverse_flag=1;

		}

	
	}

}




int main(int argc, char *argv[])
{
	Node *head;
	head=initList();

	//printRevRecursive(head);
	//printf("\n");
	//head=reverseList(head);
	printList(head);
	reverse_every_alternate_k(&head,3);
	printList(head);

}