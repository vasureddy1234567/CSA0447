#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int i, j, temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int req[100], n, head, disk_size;
    int i, pos, seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    sort(req, n);

    for(pos = 0; pos < n; pos++) {
        if(req[pos] > head)
            break;
    }

    printf("\nSeek Sequence: ");

    for(i = pos; i < n; i++) {
        printf("%d ", req[i]);
        seek += abs(req[i] - head);
        head = req[i];
    }

    seek += abs((disk_size - 1) - head);
    head = 0;
    seek += disk_size - 1;

    for(i = 0; i < pos; i++) {
        printf("%d ", req[i]);
        seek += abs(req[i] - head);
        head = req[i];
    }

    printf("\nTotal Seek Time = %d\n", seek);

    return 0;
}
