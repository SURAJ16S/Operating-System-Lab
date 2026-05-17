#include <stdio.h>
#include <unistd.h>

int main() {
    // execvp() passes arguments as array and searches PATH .
    char *args[] = {"ps", NULL};
    execvp("ps", args);
    return 0;
}
