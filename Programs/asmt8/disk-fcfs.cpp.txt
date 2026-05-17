#include <iostream>
#include <cmath> // Required for the abs() function in C++

using namespace std;

int main() {
    int n, i, head, total = 0;
    
    cout << "Enter number of requests: ";
    cin >> n;
    
    int req[n];
    
    cout << "Enter request sequence:\n";
    for(i = 0; i < n; i++) {
        cin >> req[i];
    }
        
    cout << "Enter initial head position: ";
    cin >> head;
    
    cout << "\nGantt Chart:\n" << head;
    
    for(i = 0; i < n; i++) {
        total += abs(head - req[i]);
        head = req[i];
        cout << " -> " << head;
    }
    
    cout << "\n\nTotal Head Movement = " << total << "\n";
    
    return 0;
}