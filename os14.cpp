#include <stdio.h>
#include <string.h>

int main() {
    int n, i, found = 0;
    char files[20][50], search[50];

    printf("Enter number of files: ");
    scanf("%d", &n);

    printf("Enter file names:\n");
    for(i = 0; i < n; i++) {
        scanf("%s", files[i]);
    }

    printf("\nFiles in directory:\n");
    for(i = 0; i < n; i++) {
        printf("%s\n", files[i]);
    }

    printf("\nEnter file to search: ");
    scanf("%s", search);

    for(i = 0; i < n; i++) {
        if(strcmp(files[i], search) == 0) {
            found = 1;
            break;
        }
    }

    if(found)
        printf("File found\n");
    else
        printf("File not found\n");

    return 0;
}
