#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    if (fork() == 0) {
        printf("Child process loading new program...\n");
        execl("./your_other_program", "your_other_program", NULL);
        printf("Exec failed! Did you compile 'your_other_program'?\n"); 
    } else {
        wait(NULL);
        printf("Parent process: Child execution complete.\n");
    }
    return 0;
}
