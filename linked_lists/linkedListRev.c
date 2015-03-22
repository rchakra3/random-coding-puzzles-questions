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


	for(i=0;i<5;i++)
	{
		node=(Node*) malloc(sizeof(Node));

		node->value=i;

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


int main(int argc, char *argv[])
{
	Node *head;
	head=initList();

	printRevRecursive(head);
	printf("\n");
	head=reverseList(head);
	printList(head);

}