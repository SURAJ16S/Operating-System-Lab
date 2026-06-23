#include <iostream>
using namespace std;

int main()
{
    int n, m;

    // Accept number of processes and resources
    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    int allocation[n][m], max[n][m], need[n][m];
    int available[m], work[m];
    int finish[n] = {0}, safeseq[n];

    // Accept Allocation Matrix
    cout << "\nEnter Allocation Matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> allocation[i][j];
        }
    }

    // Accept Maximum Matrix
    cout << "\nEnter Maximum Matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
    }

    // Accept Available Resources
    cout << "\nEnter Available Resources:\n";
    for(int i = 0; i < m; i++)
    {
        cin >> available[i];
    }

    // Calculate Need Matrix
    cout << "\nNeed Matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
            cout << need[i][j] << " ";
        }
        cout << endl;
    }

    // Initialize Work = Available
    for(int i = 0; i < m; i++)
    {
        work[i] = available[i];
    }

    int count = 0;

    // Banker's Algorithm
    while(count < n)
    {
        int found = 0;

        for(int i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int j;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                        break;
                }

                if(j == m)
                {
                    for(int k = 0; k < m; k++)
                    {
                        work[k] = work[k] + allocation[i][k];
                    }

                    safeseq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            cout << "\nSystem is in Unsafe State\n";
            return 0;
        }
    }

    // Safe State
    cout << "\nSystem is in Safe State\n";
    cout << "Safe Sequence: ";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << safeseq[i];

        if(i != n - 1)
            cout << " -> ";
    }

    cout << endl;

    return 0;
}
