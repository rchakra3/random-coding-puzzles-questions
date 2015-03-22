#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	char c;
	char word_end_flag;
	struct Node *arrray[26];
}Node;


void trie_init(Node **head){

	int i=0;

	if(*head ==NULL){
		*head =(Node*) malloc(sizeof(Node));
		(*head)->c = '1';
		(*head)->word_end_flag=0;

		for(i=0;i<26;i++){
			(*head)->arrray[i] = NULL;
		}
	}
}

int search_trie(Node *head,char *word){

	printf("Searching for:%s\n",word);

	if(head==NULL){
		printf("Head is null\n");
		return 0;
	}
	printf("Current node's char:%c\n",head->c);

	if(word[1]=='\0'){
		if(head->word_end_flag ==1){
			return 1;
		}
		else
			return 0;
	}
	else{
		if(head->c !='1')
			return search_trie((head->arrray[word[0]-'a']),(++word));
		else{
			return search_trie((head->arrray[word[0]-'a']),word);
		}
	}
}


void trie_insert(Node **head,char *word){

	Node *current_node=NULL;

	current_node= *head;
	int curr_char=-1;
	Node *next_node=NULL;

	printf("word:%s\n",word);
	
	if(word[0]!='\0'){
		next_node=current_node->arrray[word[0]-'a'];

		if(next_node==NULL){
			printf("At node char:%c, Creating node for character %c\n",(*head)->c,word[0]);
			//current_node->arrray[word[0]-'a'] = (Node*) malloc(sizeof(Node));
			trie_init(&(current_node->arrray[word[0]-'a']));
			next_node=current_node->arrray[word[0]-'a'];
			next_node->c=word[0];
		}
		word++;
		trie_insert(&next_node,word);
	}
	else{
		printf("Word ends at character %c\n",(*head)->c);
		(*head)->word_end_flag=1;
	}

		
}


int main(int argc, char *argv[]){

	int count=atoi(argv[1]);
	int i=0;

	Node *trie_head=NULL;

	trie_init(&trie_head);

	for(i=0;i<count;i++){
		trie_insert(&trie_head,argv[2+i]);
	}

	int result=0;

	result=search_trie(trie_head,"abcd");

	printf("Does abcd exist? :%d\n",result);
}
