#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process (PID %d) running...\n", getpid());
        sleep(2);
    } else {
        waitpid(pid, NULL, 0); // Waits specifically for 'pid'
        printf("Parent process: Child (PID %d) finished.\n", pid);
    }
    return 0;
}
