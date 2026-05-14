#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd;
    char writeBuffer[] = "Hello UNIX";
    char readBuffer[20];

    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    write(fd, writeBuffer, sizeof(writeBuffer));

    lseek(fd, 0, SEEK_SET);

    read(fd, readBuffer, sizeof(writeBuffer));

    printf("File Content: %s\n", readBuffer);

    close(fd);

    return 0;
}
