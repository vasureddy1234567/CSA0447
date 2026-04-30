#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE readPipe, writePipe;
    SECURITY_ATTRIBUTES sa;
    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    char message[] = "Hello from Parent!";
    char buffer[100];
    DWORD bytesRead, bytesWritten;

    // Allow handle inheritance
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;

    // Create pipe
    if (!CreatePipe(&readPipe, &writePipe, &sa, 0)) {
        printf("Pipe creation failed\n");
        return 1;
    }

    // Setup child process
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.hStdInput = readPipe;
    si.dwFlags |= STARTF_USESTDHANDLES;

    ZeroMemory(&pi, sizeof(pi));

    // Create child process (same program)
    if (!CreateProcess(NULL, "cmd.exe", NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
        printf("Process creation failed\n");
        return 1;
    }

    // Parent writes to pipe
    WriteFile(writePipe, message, sizeof(message), &bytesWritten, NULL);

    printf("Parent sent: %s\n", message);

    CloseHandle(writePipe);
    CloseHandle(readPipe);

    return 0;
}
