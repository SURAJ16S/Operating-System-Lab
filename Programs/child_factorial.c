#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num = 5;
    if (fork() == 0) {
        int fact = 1;
        for(int i = 1; i <= num; i++) {
            fact *= i;
        }
        printf("Child Process: The factorial of %d is %d\n", num, fact);
    } else {
        wait(NULL);
        printf("Parent Process: Factorial calculation complete.\n");
    }
    return 0;
}
