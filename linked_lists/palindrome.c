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


int is_Palindrome(Node **left,Node *right){

    int rest_is_pal=0;

    if(right==NULL)
        return 1;

    rest_is_pal=is_Palindrome(left,right->next);
    if(!rest_is_pal)
        return 0;

    if((*left)->data == right->data){
        *left =(*left)->next;
        return 1;
    }

    else
        return 0;
}

Node *return_mid(Node *head){

    Node *slow=head;
    Node *fast=head;

    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}


int main()
{
    Node *start = NULL;
 
    /* The constructed linked list is the opposite of:
     1->2->3->4->5->6->7 */
    push(&start, 1);
    push(&start, 2);
    push(&start, 3);
    push(&start, 5);
    push(&start, 3);
    push(&start, 2);
     push(&start, 1);

 
    printf("\nLinked list\n");
    printList(start);
 


    printf("Palindrome?:%d\n",is_Palindrome(&start,start));
 
    return 0;
}