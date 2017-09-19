#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Threads will attempt to sell their tickets until they are all gone */

void* sell_tickets(void*);

#define num_tickets 35
#define num_threads 4

static int tickets = num_tickets;
static sem_t ticket_lock;

typedef int bool;
#define true 1
#define false 0

void main(int argc, char*argv[]){
	srand(time(NULL));

	pthread_t threads[num_threads];
	int i;

	/* Create the semaphore lock */
	if(sem_init(&ticket_lock,0,1)){
		printf("Error initializing semaphore\nExiting...\n");
		exit(-1);
	}

	/* Create the threads */
	for(i=0; i<num_threads; i++){
		if(pthread_create(&threads[i],NULL,sell_tickets,(void*)i)){
			printf("Error creating thread %d\nExiting...\n",i);
			exit(-1);
		}
	}

	/* Join the threads */
	for(i=0;i<num_threads;i++){
		if(pthread_join(threads[i],NULL)){
			printf("Error joining thread %d\nExiting...\n",i);
			exit(-1);
		}
	}

}

void* sell_tickets(void* threadid){
	int id = (int)threadid;
	bool done = false;
	int count = 0;

	int r = 0;
	int i;
	while(!done){

		/* Simulate some kind of delay for the sake of randomness */
		r = rand()%1000000;
		for(i=0;i<r;i++){}

		/* Enter the critical section once it is your turn */
		sem_wait(&ticket_lock);
		if(tickets == 0){
			done = true;
		}
		else{
			tickets--;
			count++;
		}
		sem_post(&ticket_lock);
		/* Leave the critical section */

	}
	printf("Thread %d sold %d tickets\n",id,count);

}





