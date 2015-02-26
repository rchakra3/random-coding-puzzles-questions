#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include "stack.h"

#define MAX(a,b) ( ( a > b) ? a : b )

void tree_print_inorder(Node *root);
void tree_print_inorder_nonr(Node *root);
void tree_print_inorder_official_nonr(Node *root);
void tree_print_postorder(Node *root);
Node *insert(Node *root,int value);
Node *delete(Node *root,int value);
Node* search(Node *root,int value);
Node* getSuccessor(Node *root);
int size(Node *root);
int maxDepth(Node *root);
int minValue(Node *root);
void hasPathSum(Node *node, int sum);
void printPaths(Node *root);
void mirror(Node *root);
void doubleTree(Node* node);
Node *populateRoot2();
int isBST(Node *root);

int main(int argc,char *argv[])
{
	int opt,val;
	Node *root=NULL,*temp=NULL,*root2=NULL;
	
	while(1)
	{
		printf("1.Size\n2.Insert\n3.Search\n4.Delete\n5.Max Depth\n6.Min Value\n7.Print Tree in-order\n8.Print Tree post-order\n9.Check if any path to leaf equals sum\n");
		printf("10.Print all Paths\n11.Mirror\n");
		scanf("%d",&opt);


		switch(opt)
		{
			case 1:	printf("\nSize:%d\n",size(root));
					break;

			case 2: printf("Enter Value:\n");
					scanf("%d",&val);
					printf("Address of root:%p\nValue of root:%p\n",&root,root);
					root=insert(root,val);
					printf("Address of root:%p\nValue of root:%p\n",&root,root);
					break;

			case 3: printf("Enter Value:\n");
					scanf("%d",&val);
					temp=search(root,val);
					if(temp!=NULL)
						printf("Success!\n");
					break;

			case 4: printf("Enter Value:\n");
					scanf("%d",&val);
					root=delete(root,val);
					break;

			case 5: printf("Max Depth:%d\n", maxDepth(root));
					break;

			case 6: printf("Min Value:%d\n", minValue(root));
					break;

			case 7: tree_print_inorder(root);
					break;

			case 8: tree_print_postorder(root);
					break;

			case 9: printf("Enter sum:\n");
					scanf("%d",&val);
					hasPathSum(root,val);
					break;

			case 10: printPaths(root);
					 break;

			case 11: mirror(root);
					 break;

			case 12: doubleTree(root);
					 break;

			case 13: printf("%d\n\n\n",sameTree(root,root2));
					 break;

			case 14: //root2=populateRoot2();
					  break;

			case 15: tree_print_inorder(root2);
					  break;

			case 16: printf("%d\n\n",isBST(root));
					  break;

			case 17: tree_print_inorder_official_nonr(root);
					 break;
		}
	}

	return 1;
}


void tree_print_inorder_official_nonr(Node *root){

	Node *traverser=root;
	Stack *s=(Stack*) malloc(sizeof(Stack));

	while(!stack_isempty(s)) {

		if(traverser!=NULL){
			stack_push(s,traverser);
			traverser=traverser->left;
		}
		else{
			traverser=stack_pop(s);
			
			if(traverser!=NULL)
			{
				printf("%d ", traverser->value);
				
				if(traverser->right!=NULL){
					traverser=traverser->right;
				}
				else
					traverser=NULL;
			}
		}
	}
	printf("\n\n");
}


void tree_print_inorder_nonr(Node *root){
	
	Node *traverser=NULL,*temp_traverser;
	Stack *s=(Stack*) malloc(sizeof(Stack));

	stack_push(s,root);

	while((traverser=stack_pop(s))!=NULL){

		while(traverser->left!=NULL){
			stack_push(s,traverser);
			traverser=traverser->left;
		}

		printf("%d\n",traverser->value);
		temp_traverser=traverser;
		traverser=stack_pop(s);

		if(traverser!=NULL){

			printf("%d\n", traverser->value);

			if(traverser->right!=NULL){
				stack_push(s,traverser->right);
			}
		}
		else if(temp_traverser->right!=NULL){
			stack_push(s,temp_traverser->right);
		}
		else
			break;
			
	}

}


int isBST(Node *root)
{
	return BST_checker(root,0,INT_MAX);
}


int BST_checker(Node *root,int min, int max)
{
	int left_result=0,right_result=0;

	if(root==NULL)
		return 1;

	if(root->value <min || root->value > max)
		return 0;

	left_result=BST_checker(root->left,min,root->value);

	right_result=BST_checker(root->right,root->value,max);

	if(left_result+right_result >1)
		return 1;

	return 0;
}


int sameTree(Node *root,Node *root2)
{

	if(root==NULL&&root2==NULL)
	{
		//printf("Reached a leaf:%d\n",root2->value);
		return 1;
	}	

	if(root==NULL||root2==NULL)
		return 0;

	if(root->value!=root2->value)
		return 0;

	if((sameTree(root->left,root2->left)+sameTree(root->right,root2->right))==2)
		return 1;

	return 0;

}

void doubleTree(Node* node)
{
	if(node==NULL)
		return;

	Node *copy=(Node*) malloc(sizeof(Node));

	copy->value=node->value;

	copy->left=node->left;

	node->left=copy;

	doubleTree(node->left);
	doubleTree(node->right);
}

void mirror(Node *root)
{
	Node *temp_left;
	if(root==NULL)
		return;
	
	temp_left=root->left;
	root->left=root->right;
	root->right=temp_left;

	mirror(root->left);
	mirror(root->right);

}


void printPathHelper(Node *root,char *path_till_now)
{
	char *new_path=NULL;
	int length=0;
	if(root==NULL)
		return;

	//code to calculate size from: http://stackoverflow.com/a/8257728/2021149
	length=(int)(ceil(log10(root->value))+1);

	if(strcmp(path_till_now,""))
	{

		length+=strlen(path_till_now);
		new_path=(char*) malloc(sizeof(char)*length);
		sprintf(new_path,"%s->%d",path_till_now,root->value);
	}

	else
	{
		new_path=(char*) malloc(sizeof(char)*length);
		sprintf(new_path,"%d",root->value);
	}

	if(root->left==NULL&&root->right==NULL)
		puts(new_path);

	if(root->right!=NULL)
		printPathHelper(root->right,new_path);

	if(root->left!=NULL)
	{
		printPathHelper(root->left,new_path);
	}
}


void printPaths(Node *root)
{
	
	printPathHelper(root,"");
}

int addSum(Node *node,int sum_to_check,int sum_till_now)
{
	int result=0;

	if(node==NULL)
		return 0;

	if(node->left==NULL&&node->right==NULL)
	{
		if(node->value+sum_till_now==sum_to_check)
			return 1;

		else
			return 0;
	}

	if(node->right!=NULL)
	{
		result=addSum(node->right,sum_to_check,node->value+sum_till_now);

		if(result>0)
			return 1;
	}

	if(node->left!=NULL)
	{
		result=addSum(node->left,sum_to_check,node->value+sum_till_now);

		if(result>0)
			return 1;
	}

	return 0;

}

void hasPathSum(Node *node, int sum)
{
	if(addSum(node,sum,0)>0)
		printf("Exists!\n");
	else
		printf("Does not exist\n");
}


int minValue(Node *root)
{
	Node *traverser=root;

	if(traverser==NULL)
		return -1;//ERROR

	while(traverser->left!=NULL)
		traverser=traverser->left;

	return traverser->value;
}

int size(Node *root)
{
	if(root==NULL)
		return 0;

	if(root->left==NULL&&root->right==NULL)
		return 1;

	return (1+ size(root->left) +size(root->right));
}

int maxDepth(Node *root)
{
	if(root==NULL)
		return 0;

	return (1+MAX(maxDepth(root->left),maxDepth(root->right)));
}

void tree_print_inorder(Node *root){

	if(root==NULL)
		return;

	tree_print_inorder(root->left);
	printf("%d ", root->value);
	tree_print_inorder(root->right);

}

void tree_print_postorder(Node *root){

	if(root==NULL)
		return;

	tree_print_postorder(root->left);
	tree_print_postorder(root->right);
	printf("%d ", root->value);
	

}

Node *insert(Node *root,int val)
{
	Node *newNode=NULL;

	

	if(root==NULL)
	{
		newNode=(Node*) malloc(sizeof(Node));

		newNode->value=val;
		newNode->left=NULL;
		newNode->right=NULL;
		return newNode;
	}

	if(root->value>val)
	{
		root->left=insert(root->left,val);
	}
	else
	{
		root->right=insert(root->right,val);
	}

	return root;

}

Node *delete(Node *root,int val)
{
	Node *temp;

	if(root==NULL)
	{
		printf("Does not exist\n");
		return NULL;
	}

	if(root->value==val)
	{
		if(root->left==NULL)
		{
			root=root->right;
		}
		else if(root->right==NULL)
		{
			root=root->left;
		}
		else
		{
			root=getSuccessor(root);
		}
	}

	else if(root->value<val)
		root->right=delete(root->right,val);
	
	else
		root->left=delete(root->left,val);

	return root;
}

Node *getSuccessor(Node *root)
{
	Node *traverser=root->right;
	Node *parent=NULL;

	if(traverser==NULL)
		return NULL;

	if(traverser->left==NULL)
	{
		traverser->left=root->left;
		free(root);
		return traverser;
	}

	while(traverser->left!=NULL)
	{
		parent=traverser;
		traverser=traverser->left;
	}

	parent->left=traverser->right;

	traverser->right=root->right;
	traverser->left=root->left;
	free(root);
	return traverser;
}

Node *search(Node *root,int val){

	if(root==NULL)
		return NULL;

	if(root->value==val)
		return root;

	if(root->value>val)
		return search(root->left,val);

	return search(root->right,val);
}