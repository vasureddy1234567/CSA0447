#include <stdio.h>

int main() {
    int mutex=1, full=0, empty=5, x=0;

    printf("Producer Produces Item\n");
    mutex--;
    full++;
    empty--;
    x++;
    mutex++;

    printf("Consumer Consumes Item\n");
    mutex--;
    full--;
    empty++;
    x--;
    mutex++;

    return 0;
}
