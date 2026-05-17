#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>

// fork() implementation
void run_fork() {
    pid_t pid = fork();
    if (pid < 0) {
        printf("Fork failed\n"); 
    } else if (pid == 0) {
        printf("Child Process\n"); 
        printf("Child PID: %d\n", getpid()); 
    } else {
        printf("Parent Process\n"); 
        printf("Parent PID: %d\n", getpid()); 
    }
}

// wait() implementation
void run_wait() {
    if (fork() == 0) {
        printf("Child process executing...\n"); 
        sleep(3); 
        printf("Child exiting\n"); 
        exit(0);
    } else {
        wait(NULL); // Parent waits for child process to terminate.
        printf("Parent resumes after child finishes\n"); 
    }
}

// exec() implementation
void run_exec() {
    printf("Executing ls command\n"); 
    execlp("ls", "ls", "-1", NULL); // Searches command in PATH variable.
    printf("This line will not execute\n"); 
}

// ps implementation
void run_ps() {
    system("ps -aux"); 
}

// join() implementation using threads
void* thread_function(void* arg) {
    printf("Thread is running\n"); 
    return NULL; 
}

void run_join() {
    pthread_t t1; 
    pthread_create(&t1, NULL, thread_function, NULL); 
    pthread_join(t1, NULL); // Waits for thread to finish.
    printf("Thread finished execution\n"); 
}

int main() {
    int choice;
    printf("1. fork\n2. wait\n3. exec\n4. ps\n5. join\nEnter choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: run_fork(); break;
        case 2: run_wait(); break;
        case 3: run_exec(); break;
        case 4: run_ps(); break;
        case 5: run_join(); break;
        default: printf("Invalid choice\n");
    }
    return 0;
}
