#include <iostream>

using namespace std;

int main() {
    int n, i, j;
    int bt[20], wt[20], tat[20], p[20];

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter Burst Time:\n";
    for(i = 0; i < n; i++) {
        cin >> bt[i];
        p[i] = i + 1;
    }

    // --- SORTING LOGIC WITH BUILT-IN SWAP ---
    // Sort processes in ascending order based on Burst Time
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                // Swap the burst times
                swap(bt[i], bt[j]);

                // Swap the corresponding process IDs
                swap(p[i], p[j]);
            }
        }
    }
    // ----------------------------------------

    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    cout << "\nProcess\tBT\tWT\tTAT\n";
    for(i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    return 0;
}