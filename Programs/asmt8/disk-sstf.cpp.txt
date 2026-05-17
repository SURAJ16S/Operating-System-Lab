#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, i, j, head, total = 0, min, index;
    
    cout << "Enter number of requests: ";
    cin >> n;
    
    int req[n], done[n];
    
    cout << "Enter requests:\n";
    for(i = 0; i < n; i++) {
        cin >> req[i];
        done[i] = 0;
    }
    
    cout << "Enter head position: ";
    cin >> head;
    
    for(i = 0; i < n; i++) {
        min = 9999;
        for(j = 0; j < n; j++) {
            if(!done[j] && abs(head - req[j]) < min) {
                min = abs(head - req[j]);
                index = j;
            }
        }
        done[index] = 1;
        total += min;
        head = req[index];
        cout << " -> " << head;
    }
    
    cout << "\nTotal Head Movement = " << total << "\n";
    
    return 0;
}