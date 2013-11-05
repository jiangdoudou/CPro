#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void Pthread_mutex_lock(pthread_mutex_t *mutex)
{
	if(pthread_mutex_lock(mutex) < 0){
		perror("pthread_mutex_lock");
		exit(EXIT_FAILURE);
	}
}
void Pthread_mutex_unlock(pthread_mutex_t *mutex)
{
	if(pthread_mutex_unlock(mutex) < 0){
		perror("pthread_mutexunlock");
		exit(EXIT_FAILURE);
	}

}

void Pthread_create(pthread_t *tid, const pthread_attr_t *attr, 
		void *(*func)(void *), void *arg)
{
	if(pthread_create(tid, attr, func, arg) < 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
}

int Pthread_join(pthread_t tid, void **ret)
{
	int err_num;
	if((err_num = pthread_join(tid, NULL)) < 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	return(err_num);
}
