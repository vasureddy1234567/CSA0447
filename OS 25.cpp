#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd = open("test.txt", O_RDONLY);

    printf("File Descriptor: %d\n", fd);

    lseek(fd, 0, SEEK_SET);

    struct stat st;
    stat("test.txt", &st);
    printf("Size: %ld bytes\n", st.st_size);

    DIR *d = opendir(".");
    struct dirent *dir;

    printf("\nDirectory Contents:\n");
    while((dir = readdir(d)) != NULL)
        printf("%s\n", dir->d_name);

    closedir(d);
    close(fd);
    return 0;
}
