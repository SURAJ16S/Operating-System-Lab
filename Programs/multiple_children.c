#include <stdio.h>
#include <unistd.h>

int main() {
    for(int i = 0; i < 3; i++) {
        if(fork() == 0) {
            printf("Child %d created. PID: %d\n", i+1, getpid());
            return 0; // Exits so the child doesn't create its own children
        }
    }
    return 0;
}
