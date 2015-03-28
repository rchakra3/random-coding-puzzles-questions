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


void remove_loop(Node *head){

	Node *slow=head,*fast=head,*last=NULL;

	while(fast!=NULL && fast->next !=NULL){
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow)
			break;
	}
	if(fast!=slow) //there is no loop!
		return;

	slow=head;

	while(slow!=fast){
		last=fast;
		slow=slow->next;
		fast=fast->next;
	}

	last->next=NULL;


}


int main(int argc, char *argv[])
{
	Node *head;
	head=initList();
	head->next->next->next->next->next = head->next->next;
	//printRevRecursive(head);
	//printf("\n");
	//head=reverseList(head);
	//printList(head);
	remove_loop(head);
	printList(head);

}