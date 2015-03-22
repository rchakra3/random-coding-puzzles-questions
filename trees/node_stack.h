typedef struct Node_Stack{
	Node_container *head;
}Node_Stack;

void Stack_push(Node_Stack **stack,Node *new_node){

	if(*stack ==NULL){
		*stack= (Node_Stack*) malloc(sizeof(Node_container));
		(*stack)->head=NULL;
		Stack_push(stack,new_node);
		return;
	}

	Node_container *new_container=(Node_container*) malloc(sizeof(Node_container));
	new_container->node=new_node;
	new_container->next=(*stack)->head;
	(*stack)->head=new_container;

}

Node *Stack_pop(Node_Stack **stack){

	Node_container *first=(*stack)->head;

	if(first==NULL)
		return NULL;

	(*stack)->head=first->next;

	return first->node;
}

