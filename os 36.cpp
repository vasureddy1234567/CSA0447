#include <stdio.h>

struct Block {
    int blockNo;
    int next;
};

int main() {
    int n, i;

    printf("Enter number of blocks in file: ");
    scanf("%d", &n);

    struct Block file[n];

    printf("Enter block numbers:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &file[i].blockNo);

        if(i == n - 1)
            file[i].next = -1;
        else
            file[i].next = i + 1;
    }

    printf("\nLinked File Allocation:\n");
    printf("Start Block: %d\n", file[0].blockNo);
    printf("End Block: %d\n", file[n-1].blockNo);

    printf("File Blocks:\n");
    for(i = 0; i < n; i++) {
        printf("%d -> ", file[i].blockNo);

        if(file[i].next == -1)
            printf("NULL");
    }

    return 0;
}
