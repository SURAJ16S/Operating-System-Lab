/*
Step 1:
Create file with .c extension
Example:
roundrobin.c

Step 2:
Compile program
gcc roundrobin.c

Step 3:
Run program
./a.out
*/

#include <stdio.h>

int main() {

    int n, i, tq;
    int bt[10], rem[10], wt[10], tat[10];
    int time = 0, done;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {

        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);

        rem[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while(1) {

        done = 1;

        for(i = 0; i < n; i++) {

            if(rem[i] > 0) {

                done = 0;

                if(rem[i] > tq) {

                    time += tq;
                    rem[i] -= tq;

                } else {

                    time += rem[i];

                    wt[i] = time - bt[i];

                    rem[i] = 0;
                }
            }
        }

        if(done == 1)
            break;
    }

    printf("\n-----------------------------------\n");
    printf("Process\tBT\tWT\tTAT\n");
    printf("-----------------------------------\n");

    for(i = 0; i < n; i++) {

        tat[i] = bt[i] + wt[i];

        avgWT += wt[i];
        avgTAT += tat[i];

        printf("P%d\t%d\t%d\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);
    }

    printf("-----------------------------------\n");

    printf("Average Waiting Time = %.2f\n", avgWT / n);
    printf("Average Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}