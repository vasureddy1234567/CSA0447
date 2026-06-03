#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char line[200], word[50];

    printf("Enter word: ");
    scanf("%s", word);

    fp = fopen("sample.txt","r");

    while(fgets(line,sizeof(line),fp))
        if(strstr(line,word))
            printf("%s",line);

    fclose(fp);
    return 0;
}
