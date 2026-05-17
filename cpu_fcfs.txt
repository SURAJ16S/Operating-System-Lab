/*
Step 1:
Create file with .c extension
Example:
fcfs.c

Step 2:
Compile program
gcc fcfs.c

Step 3:
Run program
./a.out
*/

#include <stdio.h>

int main() {

    int n, i;
    int bt[10], wt[10], tat[10];
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    printf("\n-----------------------------------\n");
    printf("Process\tBT\tWT\tTAT\n");
    printf("-----------------------------------\n");

    for(i = 0; i < n; i++) {

        tat[i] = wt[i] + bt[i];

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