/*
Step 1:
Create file with .c extension
Example:
disk_fcfs.c

Step 2:
Compile program
gcc disk_fcfs.c

Step 3:
Run program
./a.out
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int req[50], n, head, i, seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nOrder of Service:\n");

    for(i = 0; i < n; i++) {

        printf("%d -> ", req[i]);

        seek += abs(head - req[i]);
        head = req[i];
    }

    printf("\nTotal Seek Time = %d\n", seek);

    return 0;
}