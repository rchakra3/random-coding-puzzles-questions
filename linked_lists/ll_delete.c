#include<stdio.h>
#include<stdlib.h>
 

/* A linked list node */
typedef struct node
{
    int data;
    struct node *next;
}Node;


/* Function to add a node at the beginning of Linked List */
void push(Node ** head_ref, int new_data)
{
    Node * new_node = (Node *) malloc(sizeof(struct node));
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

void delete_list(Node **head){

    Node *traverser=*head;
    Node *prev=NULL;

    while(traverser!=NULL){
        prev=traverser;
        traverser=traverser->next;
        printf("\nFreeing node with value:%d",prev->data);
        free(prev);
    }

    *head=NULL;

}

void delete_alternate(Node **head){

    Node *traverser=*head;
    Node *temp=NULL;
    int node_num=0;

    while(traverser!=NULL && traverser->next!=NULL){   
       temp=traverser->next;
       traverser->next=traverser->next->next;
       traverser=traverser->next;

       if(temp!=NULL){
        printf("Freeing node with value:%d\n",temp->data);
        free(temp);
        }
    }

}



int main()
{
    Node *start = NULL;
 
    /* The constructed linked list is the opposite of:
     1->2->3->4->5->6->7 */
    //push(&start, 1);
    //push(&start, 2);
    //push(&start, 3);
    push(&start, 5);
    push(&start, 6);
    push(&start, 7);
     push(&start, 4);

 
    printf("\nLinked list\n");
    printList(start);
 
    delete_alternate(&start);

    printf("\nAfter deletion:\n");
    printList(start);
 
    return 0;
}