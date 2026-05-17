#include <iostream>

using namespace std;

int main() {
    int n, i, time = 0, remain, tq;
    int bt[20], rt[20];

    cout << "Enter number of processes: ";
    cin >> n;
    remain = n;

    cout << "Enter burst times:\n";
    for(i = 0; i < n; i++) {
        cin >> bt[i];
        rt[i] = bt[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    // --- REFACTORED LOOP START ---
    // Initializing variables before the loop for better readability
    time = 0;
    i = 0;
    
    // A clean while loop instead of the complex for-loop
    while (remain > 0) {
        if(rt[i] <= tq && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            cout << "P" << i+1 << " finished at time " << time << "\n";
            remain--;
        }
        else if(rt[i] > 0) {
            rt[i] -= tq;
            time += tq;
        }
        
        // Cycle to the next process
        if(i == n - 1) {
            i = 0;
        } else {
            i++;
        }
    }
    // --- REFACTORED LOOP END ---

    return 0;
}