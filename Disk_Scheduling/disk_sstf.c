/*
Step 1:
Create file with .c extension
Example:
sstf.c

Step 2:
Compile program
gcc sstf.c

Step 3:
Run program
./a.out
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int req[50], visited[50] = {0};
    int n, head, i, j, seek = 0;
    int min, index, dist;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nOrder of Service:\n");

    for(i = 0; i < n; i++) {

        min = 9999;

        for(j = 0; j < n; j++) {

            if(!visited[j]) {

                dist = abs(head - req[j]);

                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;

        printf("%d -> ", req[index]);

        seek += abs(head - req[index]);
        head = req[index];
    }

    printf("\nTotal Seek Time = %d\n", seek);

    return 0;
}