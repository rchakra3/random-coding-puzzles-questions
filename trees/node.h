
typedef struct node{
	int value;
	struct node *left;
	struct node *right;
}Node;


typedef struct Node_container{
	Node *node;
	struct Node_container *next;
}Node_container;