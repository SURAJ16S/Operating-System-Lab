#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, i, head, total = 0, disk_size = 199;
    
    cout << "Enter number of requests: ";
    cin >> n;
    
    int req[n];
    
    cout << "Enter requests:\n";
    for(i = 0; i < n; i++) {
        cin >> req[i];
    }
        
    cout << "Enter head position: ";
    cin >> head;
    
    // Simple sorting
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(req[i] > req[j]) {
                swap(req[i],req[j]);
            }
        }
    }
    
    cout << "\nGantt Chart:\n" << head;
    
    // Move right
    for(i = 0; i < n; i++) {
        if(req[i] >= head) {
            total += abs(head - req[i]);
            head = req[i];
            cout << " -> " << head;
        }
    }
    
    // Go to end
    total += abs(head - disk_size);
    head = disk_size;
    
    // Move left
    for(i = n-1; i >= 0; i--) {
        if(req[i] < head) {
            total += abs(head - req[i]);
            head = req[i];
            cout << " -> " << head;
        }
    }
    
    cout << "\nTotal Head Movement = " << total << "\n";
    
    return 0;
}