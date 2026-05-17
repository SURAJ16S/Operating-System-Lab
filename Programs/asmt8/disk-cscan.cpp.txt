#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, i, head, total = 0, disk_size = 199;
    
    cout << "Enter number of requests: ";
    cin >> n;
    
    int req[n];
    
    cout << "Enter request sequence:\n";
    for(i = 0; i < n; i++) {
        cin >> req[i];
    }
        
    cout << "Enter initial head position: ";
    cin >> head;
    
    // Store the initial head position before moving it
    int initial_head = head;
    
    // Sorting requests
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(req[i] > req[j]) {
                swap(req[i], req[j]);
            }
        }
    }
    
    cout << "\nGantt Chart:\n" << head;
    
    // Move right side
    for(i = 0; i < n; i++) {
        if(req[i] >= head) {
            total += abs(head - req[i]);
            head = req[i];
            cout << " -> " << head;
        }
    }
    
    // Go to end of disk
    total += abs(head - disk_size);
    head = disk_size;
    
    // Jump to start (0)
    total += disk_size;
    head = 0;
    
    // Move again from start
    for(i = 0; i < n; i++) {
        // FIXED CONDITION: Only process requests before the original starting point
        if(req[i] < initial_head) {
            total += abs(head - req[i]);
            head = req[i];
            cout << " -> " << head;
        }
    }
    
    cout << "\nTotal Head Movement = " << total << "\n";
    
    return 0;
}