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


struct node *merge(struct node *left_side,struct node *right_side,int size,struct node *minus_one_left){
	
	struct node *orig_left=left_side;
	struct node *orig_right=right_side;
	struct node *temp_right=NULL, *temp_left=NULL,*prev_left=NULL, *start=left_side, *left_traverser=left_side,*right_traverser=right_side;
	struct node *original_node_after_last;
	int iterator=size;

	//break off the right side
	while(iterator>0){
		left_traverser=left_traverser->next;
		iterator--;
	}
	original_node_after_last=left_traverser->next;
	left_traverser->next=NULL;
	
	//reset left traverser
	left_traverser=orig_left;

	//break off the left side
	while(left_traverser!=orig_right){
		temp_left=left_traverser;
		left_traverser=left_traverser->next;
	}
	temp_left->next=NULL;

	//reset left_traverser 
	left_traverser=orig_left;


	while(left_traverser!=NULL && right_traverser!=NULL){

		while(left_traverser->next!=NULL){

			if(left_traverser->next->data < right_traverser->data){
				prev_left=left_traverser;
				left_traverser=left_traverser->next;
			}

			else
				break;
		}



		while(right_traverser->next!=NULL){

			if(right_traverser->next->data < left_traverser->data)
				right_traverser=right_traverser->next;

			else
				break;
		}


		if(prev_left==NULL){

			start=orig_right;
		}

		if(right_traverser->data < left_traverser->data){

			if(prev_left!=NULL)
				prev_left->next=right_traverser;
			temp_right=right_traverser->next;
			right_traverser->next=left_traverser;
			right_traverser=temp_right;
			prev_left=left_traverser;
			left_traverser=left_traverser->next;
		}

		else{

			temp_right=right_traverser->next;
			temp_left=left_traverser->next;
			left_traverser->next=right_traverser;
			right_traverser->next=temp_left;
			left_traverser=temp_left;
			right_traverser=temp_right;
		}
		
	
	}

	if(minus_one_left!=NULL){
		minus_one_left->next=start;
	}

	left_traverser=start;

	while(left_traverser->next!=NULL){
		left_traverser=left_traverser->next;
	}
	left_traverser->next=original_node_after_last;

	return start;

}

struct node* sort(struct node *root,int start, int end)
{
	
	struct node *traverser=root, *left_side, *right_side,*return_val,*minus_one_left=NULL;
	int mid=(start+end)/2, iter=0;;
	
	//printf("Start:%d End:%d\n",start,end);
	if(start==end){
		
		while(iter<start){
			traverser=traverser->next;
			iter++;
		}
		return traverser;
	}
	
	left_side=sort(root,start,mid);
	if(start==0)
		root=left_side;
	right_side=sort(root,mid+1,end);
	
	//printf("Calling merge on arrays[%d-%d] and [%d-%d]\n",start,mid,mid+1,end);
	iter=start-1;
	if(iter>0)
		minus_one_left=root;

	while(iter>0)
	{
		minus_one_left=minus_one_left->next;
		iter--;
	}
	
	return_val=merge(left_side,right_side,end-start,minus_one_left);

	return return_val;
	
}
 
/* Druver program to test above function */
int main()
{
    struct node *start = NULL;
 
    /* The constructed linked list is the opposite of:
     1->2->3->4->5->6->7 */
    push(&start, 4);
    push(&start, 1);
    push(&start, 2);
    push(&start, 3);
    push(&start, 5);
    push(&start, 6);
    push(&start, 7);

 
    printf("\nLinked list before calling  mergesort() \n");
    printList(start);
 
    start=sort(start,0,6);
 
    printf("\nLinked list after calling  mergesort() \n");
    printList(start);
    printf("\n");
 
    return 0;
}
