#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<sched.h>


/*Simple program to print the sequence from 0-20 using two threads. Instead of using 2 built in mutexes, I've used a single global variable
instead. If 0 prints an even number, if 1 prints an odd number,*/

int mutex=0;

void *print_pos(){
	int num=-2;

	while(num<20){
		if(!mutex){
			printf("%d,",num+=2);
			mutex=1;
		}
		else{
			sched_yield();
		}
	}
	
}

void *print_neg(){
	int num=-1;

	while(num<19){
		if(mutex){
			printf("%d,",num+=2);
			mutex=0;
		}
		else{
			sched_yield();
		}
	}

}

int main( int argc, char *argv[]){
	
	pthread_t threads[2];

	int rc;

	
		rc=pthread_create(&threads[0],NULL,print_pos,NULL);
		if(rc){
			printf("Some kind of error creating positive:%d\n", rc);
			exit(-1);
		}
		rc=pthread_create(&threads[1],NULL,print_neg,NULL);
		if(rc){
			printf("Some kind of error creating negative:%d\n", rc);
			exit(-1);
		}

	pthread_exit(NULL);
}