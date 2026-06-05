#include <stdio.h>

int main()
{
    int owner, group, others;

    printf("Enter Owner Permission (0-7): ");
    scanf("%d", &owner);

    printf("Enter Group Permission (0-7): ");
    scanf("%d", &group);

    printf("Enter Others Permission (0-7): ");
    scanf("%d", &others);

    printf("\nLinux File Access Permissions\n");

    printf("\nOwner Permissions: ");
    if(owner & 4) printf("Read ");
    if(owner & 2) printf("Write ");
    if(owner & 1) printf("Execute ");

    printf("\nGroup Permissions: ");
    if(group & 4) printf("Read ");
    if(group & 2) printf("Write ");
    if(group & 1) printf("Execute ");

    printf("\nOthers Permissions: ");
    if(others & 4) printf("Read ");
    if(others & 2) printf("Write ");
    if(others & 1) printf("Execute ");

    printf("\n\nTypes of Users in Linux:");
    printf("\n1. Owner (User)");
    printf("\n2. Group");
    printf("\n3. Others");

    return 0;
}
