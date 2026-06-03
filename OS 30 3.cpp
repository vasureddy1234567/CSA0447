#include <stdio.h>
#include <pthread.h>

int main() {
    pthread_t t1 = pthread_self();
    pthread_t t2 = pthread_self();

    if(pthread_equal(t1,t2))
        printf("Threads are Equal\n");

    return 0;
}
