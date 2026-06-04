#include <stdio.h>

int main() {
    int n,index;

    printf("Enter Index Block: ");
    scanf("%d",&index);

    printf("Enter Number of Blocks: ");
    scanf("%d",&n);

    int block[n];

    printf("Enter Block Numbers:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&block[i]);

    printf("\nIndex Block %d contains:\n",index);

    for(int i=0;i<n;i++)
        printf("%d ",block[i]);

    return 0;
}
