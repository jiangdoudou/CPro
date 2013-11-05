#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<fcntl.h>

int main(void)
{
	sem_t *sem;
	int val;
	if((sem = sem_open("test1", O_RDWR | O_CREAT, 0644, 0))
			== SEM_FAILED){
		perror("sem_open");
		exit(EXIT_FAILURE);
	}

	if(sem_getvalue(sem, &val) < 0){
		perror("sem_getvalue");
		exit(EXIT_FAILURE);
	}
	printf("semaphore rest before posting: %d\n", val);

	if(sem_post(sem) < 0){
		perror("sem_post");
		exit(EXIT_FAILURE);
	}

	if(sem_getvalue(sem, &val) < 0){
		perror("sem_getvalue");
		exit(EXIT_FAILURE);
	}
	printf("semaphore rest after posting: %d\n", val);

	exit(EXIT_FAILURE);
}