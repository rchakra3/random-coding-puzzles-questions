typedef GenericNode StackNode;

//do not call this directly
void stack_init(StackNode **head){
	
	*head=(StackNode*)malloc(sizeof(StackNode));
	(*head)->next=NULL;
}

void stack_push(StackNode **head,int data){

	StackNode *new_node;

	if(*head == NULL){
		stack_init(head);
		(*head)->data=data;
	}

	else{
		new_node=(StackNode*) malloc(sizeof(StackNode));
		new_node->data=data;
		new_node->next=(*head);
		*head = new_node;
	}
}

int stack_pop(StackNode **head){

	int data=(*head)->data;

	StackNode *old_head=(*head);
	(*head)=(*head)->next;

	free(old_head);

	return data;

}