#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFF_SIZE 5
#define DATA_SIZE 20



sem_t buffer_empty_slots;
sem_t buffer_full_slots;
sem_t mutex;
char buff[BUFF_SIZE];
int prod_current_index;
int con_current_index;




void *Producer(void *data_to_write){

	int count=*((int*)data_to_write);
	
	while(count>0){

		sem_wait(&buffer_empty_slots);

		sem_wait(&mutex);
		//mutex has been zeroed

		printf("Producer is writing\n");

		buff[prod_current_index]=count;
		count--;
		prod_current_index++;

		prod_current_index%=BUFF_SIZE;
		sem_post(&buffer_full_slots);
		sem_post(&mutex);
		sleep(1);
	}
}



void *Consumer(void *data_to_read){

	int count=*((int*)data_to_read);

	printf("Consumer start\n");

	while(count>0){

		sem_wait(&buffer_full_slots);

		sem_wait(&mutex);

		printf("Consumer is reading:%d\n",buff[con_current_index]);

		con_current_index++;
		count--;
		con_current_index%=BUFF_SIZE;

		sem_post(&buffer_empty_slots);
		sem_post(&mutex);
		sleep(2);
	}
}






int main(int argc, char *argv[]){

	pthread_t producer,consumer;

	sem_init(&buffer_empty_slots,0,BUFF_SIZE);
	sem_init(&buffer_full_slots,0,0);
	sem_init(&mutex,0,1);

	prod_current_index=0;
	con_current_index=0;

	int size=DATA_SIZE;

	pthread_create(&consumer,NULL,Consumer,(void*)&size);

	pthread_create(&producer,NULL,Producer,(void*)&size);

	pthread_exit(NULL);

}