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
	if(head->next==NULL)
	{
		printf("%d\n", head->value);
		return;
	}

	printRevRecursive(head->next);
	printf("%d\n", head->value);
}


int main(int argc, char *argv[])
{
	Node *head;
	head=initList();

	printRevRecursive(head);
}