/*Write a C program to interchange the nodes of a linked list. Consider the linked list 1-&gt;2-&gt;3-&gt;4-&gt;5. You should get the o/p as 2-&gt;1-&gt;4-&gt;3-&gt;5. The pointers should be exchanged not just the data!*/
#include<stdio.h>
#include<stdlib.h>
 
/* A linked list node */
struct node
{
    int data;
    struct node *next;
};


/* Function to add a node at the beginning of Linked List */
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}


void rearrange(struct node **root){

	struct node *prev=NULL;
	struct node *traverser=*root;
	struct node *temp_n_n;
	struct node *new_second;

	while(traverser->next!=NULL){


		temp_n_n=traverser->next->next;

		new_second=traverser;

		traverser=traverser->next;

		traverser->next=new_second;

		new_second->next=temp_n_n;

		if(!prev){
			(*root)=traverser;
			printf("Setting root to node:%d\n",traverser->data);
		}
		else{
			prev->next=traverser;
		}

		prev=new_second;
		traverser=new_second->next;

		if(!traverser){
			break;
		}
	}
}
 
/* Druver program to test above function */
int main()
{
    struct node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling  rearrange() ");
    printList(start);
 
    rearrange(&start);
 
    printf("\n Linked list after calling  rearrange() ");
    printList(start);
 
    return 0;
}