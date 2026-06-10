#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdatomic.h>
#include <semaphore.h>

// atomic_int critical = 0;
int critical = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t sem;

void *fn1(void *)
{

    for (int i = 0; i < 100000; i++)
    {
        // pthread_mutex_lock(&mutex);
        sem_wait(&sem);
        critical++;
        sem_post(&sem);
        // pthread_mutex_unlock(&mutex);
    }
}

void *(fn2)(void *)
{
    for (int i = 0; i < 100000; i++)
    {
        // pthread_mutex_lock(&mutex);
        sem_wait(&sem);
        critical--;
        sem_post(&sem);
        // pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t id1, id2;
    sem_init(&sem, 0, 1);

    pthread_create(&id1, NULL, &fn1, NULL);
    pthread_create(&id2, NULL, &fn2, NULL);

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    printf("%d ", critical);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&sem);

    return 0;
}