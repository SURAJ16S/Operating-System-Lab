/*
Step 1:
Create file with .c extension
Example:
cscan.c

Step 2:
Compile program
gcc cscan.c

Step 3:
Run program
./a.out
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int req[50], n, head, i, j, temp;
    int seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n; i++) {

        for(j = i + 1; j < n; j++) {

            if(req[i] > req[j]) {

                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    printf("\nOrder of Service:\n");

    for(i = 0; i < n; i++) {

        if(req[i] >= head) {

            for(j = i; j < n; j++) {

                printf("%d -> ", req[j]);

                seek += abs(head - req[j]);
                head = req[j];
            }

            for(j = 0; j < i; j++) {

                printf("%d -> ", req[j]);

                seek += abs(head - req[j]);
                head = req[j];
            }

            break;
        }
    }

    printf("\nTotal Seek Time = %d\n", seek);

    return 0;
}