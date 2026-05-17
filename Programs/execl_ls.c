#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Replacing process with ls command...\n");
    // execl() passes arguments individually and requires full path .
    execl("/bin/ls", "ls", NULL);
    printf("This will not print if exec succeeds.\n");
    return 0;
}
