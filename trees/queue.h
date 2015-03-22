typedef struct Queue{
	Node_container *head;
}Queue;

void queue_enqueue(Queue **q,Node *new_node){

	if(*q ==NULL){
		*q= (Queue*) malloc(sizeof(Node_container));
		(*q)->head=NULL;
		queue_enqueue(q,new_node);
		return;
	}

	Node_container *traverser=(*q)->head;
	Node_container *new_container=(Node_container*) malloc(sizeof(Node_container));
	new_container->node=new_node;
	new_container->next=NULL;

	if(!traverser){
		(*q)->head=new_container;
	}
	else{
		while(traverser->next!=NULL){
			traverser=traverser->next;
		}

		traverser->next=new_container;
	}

}

Node *queue_dequeue(Queue **q){

	Node_container *first=(*q)->head;

	if(first==NULL)
		return NULL;

	(*q)->head=first->next;

	return first->node;
}

