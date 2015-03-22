#define STACK_SIZE 100

typedef struct stack{
	int current_top;
	Node * data[STACK_SIZE];
}Stack;



void stack_initialize(Stack *s){
	int iter=0;

	s->current_top=-1;

	for(iter=0;iter<STACK_SIZE;iter++){
		s->data[iter]=NULL;
	}
}

int stack_isempty(Stack *s){

	if(s->current_top<0)
		return 1;

	return 0;
}


void stack_push(Stack *s,Node *node){

	s->current_top++;

	if(s->current_top==STACK_SIZE){
		//error stack overflow. Always wanted to say that.
	}
	if(s->data[s->current_top]==NULL){
		s->data[s->current_top]=(Node*) malloc(sizeof(Node));
		s->data[s->current_top]=node;
	}
}

Node *stack_pop(Stack *s){
	
	Node *popped;

	if(s->current_top==-1)
	{
		return NULL;
	}

	popped=s->data[s->current_top];
	s->data[s->current_top]=NULL;
	s->current_top--;

	return popped;
}


