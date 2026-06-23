/*
Step 1:
Create file with .c extension
Example:
lru.c

Step 2:
Compile program
gcc lru.c

Step 3:
Run program
./a.out
*/

#include <stdio.h>

int main() {

    int pages[50], frames[10], time[10];
    int n, f, i, j, pos, fault = 0, cnt = 0;
    int found, min;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {

        found = 0;

        for(j = 0; j < f; j++) {

            if(frames[j] == pages[i]) {
                cnt++;
                time[j] = cnt;
                found = 1;
                break;
            }
        }

        if(found == 0) {

            min = time[0];
            pos = 0;

            for(j = 1; j < f; j++) {

                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            cnt++;
            frames[pos] = pages[i];
            time[pos] = cnt;

            fault++;

            printf("Page Fault: ");
        }

        printf("Frames: ");

        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);

        printf("\n");
    }

    printf("Total Page Faults = %d\n", fault);

    return 0;
}