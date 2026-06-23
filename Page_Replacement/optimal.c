/*
Step 1:
Create file with .c extension
Example:
optimal.c

Step 2:
Compile program
gcc optimal.c

Step 3:
Run program
./a.out
*/

#include <stdio.h>

int main() {

    int pages[50], frames[10];
    int n, f, i, j, k, pos, fault = 0;
    int found, farthest, index;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {

        found = 0;

        for(j = 0; j < f; j++) {

            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {

            pos = -1;
            farthest = i + 1;

            for(j = 0; j < f; j++) {

                index = -1;

                for(k = i + 1; k < n; k++) {

                    if(frames[j] == pages[k]) {
                        index = k;
                        break;
                    }
                }

                if(index == -1) {
                    pos = j;
                    break;
                }

                if(index > farthest) {
                    farthest = index;
                    pos = j;
                }
            }

            if(pos == -1)
                pos = 0;

            frames[pos] = pages[i];
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