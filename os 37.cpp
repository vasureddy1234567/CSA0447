#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head;
    int req[100];
    int seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d ", head);

    for(i = 0; i < n; i++) {
        seek += abs(req[i] - head);
        head = req[i];
        printf("-> %d ", head);
    }

    printf("\nTotal Seek Time = %d\n", seek);

    return 0;
}
