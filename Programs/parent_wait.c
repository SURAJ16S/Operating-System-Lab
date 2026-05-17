#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    if (fork() == 0) {
        printf("Child process is doing work...\n");
        sleep(2);
        printf("Child process terminating.\n");
    } else {
        wait(NULL); // Prevents zombie processes.
        printf("Child has terminated. Parent process exiting.\n");
    }
    return 0;
}
