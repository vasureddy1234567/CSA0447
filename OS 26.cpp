#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    fp = fopen("sample.txt","w");
    fprintf(fp,"Operating System Lab");
    fclose(fp);

    fp = fopen("sample.txt","r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);

    fclose(fp);
    remove("sample.txt");

    return 0;
}
