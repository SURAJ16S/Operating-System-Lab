#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); // Creates a new child process .

    if (pid == 0) {
        // 0 -> Child process
        printf("Hello from the Child Process! My PID is %d\n", getpid());
    } else if (pid > 0) {
        // >0 -> Parent
        printf("Hello from the Parent Process! My PID is %d, Child PID is %d\n", getpid(), pid);
    } else {
        // -1 -> Error
        printf("Fork failed.\n");
    }
    return 0;
}
