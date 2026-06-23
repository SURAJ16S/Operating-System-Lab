/*
Step 1:
Create file with .cpp extension
Example:
banker.cpp

Step 2:
Compile program
g++ banker.cpp

Step 3:
Run program
./a.out
*/

#include <iostream>
using namespace std;

int main() {

    int n, m, i, j;

    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10], safe[10];

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    cout << "\nEnter Allocation Matrix:\n";

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }

    cout << "\nEnter Maximum Matrix:\n";

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }

    cout << "\nEnter Available Resources:\n";

    for(i = 0; i < m; i++) {
        cin >> avail[i];
    }

    // Calculate Need Matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Initialize finish array
    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;

    while(count < n) {

        bool found = false;

        for(i = 0; i < n; i++) {

            if(finish[i] == 0) {

                bool possible = true;

                for(j = 0; j < m; j++) {

                    if(need[i][j] > avail[j]) {
                        possible = false;
                        break;
                    }
                }

                if(possible) {

                    for(j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }

                    safe[count] = i;
                    count++;

                    finish[i] = 1;
                    found = true;
                }
            }
        }

        if(found == false) {
            break;
        }
    }

    if(count == n) {

        cout << "\nSystem is in SAFE STATE\n";

        cout << "Safe Sequence: ";

        for(i = 0; i < n; i++) {
            cout << "P" << safe[i] << " ";
        }

        cout << endl;

    } else {

        cout << "\nSystem is NOT in Safe State\n";
    }

    cout << "\n-------------------------------------------------\n";
    cout << "Process\tAllocation\tMax\tNeed\n";
    cout << "-------------------------------------------------\n";

    for(i = 0; i < n; i++) {

        cout << "P" << i << "\t";

        for(j = 0; j < m; j++)
            cout << alloc[i][j] << " ";

        cout << "\t\t";

        for(j = 0; j < m; j++)
            cout << max[i][j] << " ";

        cout << "\t";

        for(j = 0; j < m; j++)
            cout << need[i][j] << " ";

        cout << endl;
    }

    return 0;
}