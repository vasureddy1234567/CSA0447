#include <stdio.h>

struct Directory {
    char dirname[20];
    char files[20][20];
    int filecount;
};

int main() {
    int i, j, n;

    struct Directory dir[10];

    printf("Enter number of directories: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter directory name: ");
        scanf("%s", dir[i].dirname);

        printf("Enter number of files in %s: ", dir[i].dirname);
        scanf("%d", &dir[i].filecount);

        printf("Enter file names:\n");

        for(j = 0; j < dir[i].filecount; j++) {
            scanf("%s", dir[i].files[j]);
        }
    }

    printf("\n--- Two Level Directory Structure ---\n");

    for(i = 0; i < n; i++) {
        printf("\nDirectory: %s\n", dir[i].dirname);

        for(j = 0; j < dir[i].filecount; j++) {
            printf("  %s\n", dir[i].files[j]);
        }
    }

    return 0;
}
