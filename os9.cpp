#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE hMapFile;
    char *pBuf;

    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        1024,
        "MySharedMemory"
    );

    pBuf = (char*) MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0, 0, 1024
    );

    printf("Enter data: ");
    scanf("%s", pBuf);

    printf("Data in shared memory: %s\n", pBuf);

    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}
