#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_A 1
#define STRING_B 2
#define MIN(a,b) a>b?b:a

typedef struct Trie_Node{
	char c;
	char a_visited;
	char b_visited;
	int longest_common;
	struct Trie_Node *children[26];
}Trie_Node;


void init_node(Trie_Node **node){

	*node=(Trie_Node*) malloc(sizeof(Trie_Node));
	(*node)->c=-1;
	(*node)->a_visited=-1;
	(*node)->b_visited=-1;
	(*node)->longest_common=0;

	int i;

	for(i=0;i<26;i++){
		(*node)->children[i]=NULL;
	}
}

int curr_max_substring=0;

int insert_into_trie(Trie_Node *root,char *string,int n,int mode,char **result){

	int max_length=0;
	Trie_Node *start_node=NULL,*traverser=root;
	char *temp=(char*) malloc(2);

	int i=0;
	char curr_char;
	while(i<n){
		curr_char=string[i];

		if(traverser->children[curr_char-'a']==NULL){
			init_node(&(traverser->children[curr_char-'a']));
		}
		traverser=traverser->children[curr_char-'a'];
		traverser->c=curr_char;

		if(mode==STRING_A){
			traverser->a_visited=1;
		}
		else{
			if(i==0 && traverser->a_visited==1){
				(*result)=(char*) malloc(100);
				temp[0]=traverser->c;
				temp[1]='\0';
				strcpy((*result),temp);
				max_length++;
			}
			else if(traverser->a_visited==1){
				temp[0]=traverser->c;
				temp[1]='\0';
				strcat((*result),temp);
				max_length++;
			}

			traverser->b_visited=1;
		}
		i++;
	}

	return max_length;
}


void lc_substring(char *string1,int n1,char *string2,int n2,Trie_Node *root){

	char *result_string=NULL,*final_result=NULL;
	int i=0;
	int current_max=0,final_max=0;

	if(n1>n2){
		while(i<n1){
			result_string=NULL;
			insert_into_trie(root,(string1+i),n1-i,STRING_A,&result_string);
			i++;
		}
		i=0;

		while(i<n2){
			result_string=NULL;
			current_max=insert_into_trie(root,(string2+i),n2-i,STRING_B,&result_string);
			if(current_max>final_max){
				final_result=result_string;
				final_max=current_max;
			}
			i++;
		}
	}
	else{
		i=0;

		while(i<n2){
			result_string=NULL;
			insert_into_trie(root,(string2+i),n2-i,STRING_A,&result_string);
			i++;
		}
		i=0;

		while(i<n1){
			result_string=NULL;
			current_max=insert_into_trie(root,(string1+i),n1-i,STRING_B,&result_string);
			if(current_max>final_max){
				final_result=result_string;
				final_max=current_max;
			}
			i++;
		}
	}
	printf("longest_substring:%s\n",final_result);

}

int main(int argc,char *argv[]){

	char *string1=argv[1];
	char *string2=argv[2];

	Trie_Node *root;

	init_node(&root);

	//printf("Root initialized\n");

	lc_substring(string1,strlen(string1),string2,strlen(string2),root);

}

