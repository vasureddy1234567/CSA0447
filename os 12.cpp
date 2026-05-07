#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t forks[5];

void* philosopher(void* num) {
    int id = *(int*)num;

    printf("Philosopher %d is thinking\n", id);

    pthread_mutex_lock(&forks[id]);
    pthread_mutex_lock(&forks[(id+1)%5]);

    printf("Philosopher %d is eating\n", id);
    sleep(1);

    pthread_mutex_unlock(&forks[id]);
    pthread_mutex_unlock(&forks[(id+1)%5]);

    printf("Philosopher %d finished eating\n", id);

    return NULL;
}

int main() {
    pthread_t p[5];
    int id[5];

    for(int i = 0; i < 5; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    for(int i = 0; i < 5; i++) {
        id[i] = i;
        pthread_create(&p[i], NULL, philosopher, &id[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(p[i], NULL);
    }

    return 0;
}
