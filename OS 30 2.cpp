#include <stdio.h>
#include <pthread.h>

void *fun(void *arg) {
    printf("Thread Running\n");
    return NULL;
}

int main() {
    pthread_t t;
    pthread_create(&t,NULL,fun,NULL);
    pthread_join(t,NULL);
    printf("Thread Joined\n");
    return 0;
}

