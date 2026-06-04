#include <stdio.h>

int main() {
    int start,len;

    printf("Enter starting block: ");
    scanf("%d",&start);

    printf("Enter length: ");
    scanf("%d",&len);

    printf("Allocated Blocks:\n");

    for(int i=0;i<len;i++)
        printf("%d ",start+i);

    return 0;
}
