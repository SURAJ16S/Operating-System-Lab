#include <iostream>
using namespace std;

int main() {
 int n, i;
 int bt[20], wt[20], tat[20];
 
 cout << "Enter number of processes: ";
 cin >> n;
 
 cout << "Enter Burst Time:\n";
 for(i = 0; i < n; i++) {
 cin >> bt[i];
 }
 
 wt[0] = 0;
 for(i = 1; i < n; i++) {
 wt[i] = wt[i-1] + bt[i-1];
 }
 
 for(i = 0; i < n; i++) {
 tat[i] = wt[i] + bt[i];
 }
 
 cout << "\nProcess\tBT\tWT\tTAT\n";
 for(i = 0; i < n; i++) {
 cout << "P" << i+1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
 }
 
 return 0;
}