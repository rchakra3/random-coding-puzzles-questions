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

Node *merge(Node *left_head,Node *right_head){

    Node *final=NULL;
    Node *left_traverser=left_head;
    Node *right_traverser=right_head;

    if(left_traverser->data < right_traverser->data){
        final=left_traverser;
        left_traverser=left_traverser->next;

    }
    else{
        final=right_traverser;
        right_traverser=right_traverser->next;

    }

    Node *final_traverser=final;

    while(left_traverser!=NULL && right_traverser!=NULL){

        if(left_traverser->data < right_traverser->data){
            final_traverser->next=left_traverser;
            left_traverser=left_traverser->next;
        }

        else{
            final_traverser->next=right_traverser;
            right_traverser=right_traverser->next;

        }
        final_traverser=final_traverser->next;

    }

    while(left_traverser!=NULL){
        final_traverser->next=left_traverser;
        left_traverser=left_traverser->next;
        final_traverser=final_traverser->next;

    }

    while(right_traverser!=NULL){
        final_traverser->next=right_traverser;
        right_traverser=right_traverser->next;
        final_traverser=final_traverser->next;

    }

    return final;
}

Node *sort(Node *head,int start,int end){

    Node *traverser=head;
    int i=0;

    if(start==end){
        while(i<start){
            traverser=traverser->next;
            i++;
        }
        traverser->next=NULL;
        return traverser;
    }
    if(start>end)
        return NULL;

    int mid=(start+end)/2;

    Node *right_head=sort(head,mid+1,end);
    Node *left_head=sort(head,start,mid);

    head=merge(left_head,right_head);

    return head;

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
    push(&start, 6);
    push(&start, 7);
     push(&start, 4);

 
    printf("\nLinked list before calling  mergesort() \n");
    printList(start);
 
    start=sort(start,0,6);
 
    printf("\nLinked list after calling  mergesort() \n");
    printList(start);
 
    return 0;
}