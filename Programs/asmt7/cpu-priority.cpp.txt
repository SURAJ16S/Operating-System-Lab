#include <iostream>

using namespace std;

int main() {
    int n, i, j;
    int bt[20], wt[20], tat[20], p[20], pr[20];

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter Burst Time and Priority:\n";
    for(i = 0; i < n; i++) {
        cin >> bt[i] >> pr[i];
        p[i] = i + 1;
    }

    // Sort processes based on priority using built-in swap
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(pr[i] > pr[j]) {
                swap(pr[i], pr[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    cout << "\nProcess\tPriority\tBT\tWT\tTAT\n";
    for(i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t" << pr[i] << "\t\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    return 0;
}