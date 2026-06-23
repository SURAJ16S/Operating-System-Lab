#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int status;
    if (fork() == 0) {
        printf("Child process exiting with status 7...\n");
        return 7; // Custom exit status
    } else {
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Parent process: Child exited with status %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}
