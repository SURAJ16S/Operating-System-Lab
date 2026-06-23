#include <iostream>
using namespace std;

void printFrames(int frames[], int f) {
    for (int i = 0; i < f; i++) {
        if (frames[i] == -1) cout << "- ";
        else cout << frames[i] << " ";
    }
}

void fifo(int pages[], int n, int f) {
    int frames[10];
    int pos = 0, faults = 0;
    
    for(int i = 0; i < f; i++) frames[i] = -1;

    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        
        if(!found) {
            frames[pos] = pages[i];
            pos = (pos + 1) % f;
            faults++;
        }
    }
    cout << "Total Page Faults (FIFO) = " << faults << endl;
}

// --- MERGED LRU AND OPTIMAL LOGIC ---
// mode 1 = LRU (Look Backward)
// mode 2 = Optimal (Look Forward)
void lru_optimal(int pages[], int n, int f, int mode) {
    int frames[10];
    int faults = 0;

    for(int i = 0; i < f; i++) frames[i] = -1;

    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            int pos = -1;
            int empty_found = 0;
            
            // Fill empty frames first
            for(int j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    empty_found = 1;
                    break;
                }
            }

            // If frames are full, apply logic based on mode
            if(!empty_found) {
                // target_val tracks our "farthest" metric
                int target_val = (mode == 1) ? i : -1; 
                
                for(int j = 0; j < f; j++) {
                    // last_seen tracks when we see the page
                    int last_seen = (mode == 1) ? -1 : n; 
                    
                    if(mode == 1) { 
                        // LRU: The backward scan
                        for(int k = i - 1; k >= 0; k--) {
                            if(frames[j] == pages[k]) {
                                last_seen = k;
                                break;
                            }
                        }
                    } else { 
                        // Optimal: The forward scan
                        for(int k = i + 1; k < n; k++) {
                            if(frames[j] == pages[k]) {
                                last_seen = k;
                                break;
                            }
                        }
                    }
                    
                    // LRU wants the smallest index, Optimal wants the largest index
                    if((mode == 1 && last_seen < target_val) || (mode == 2 && last_seen > target_val)) {
                        target_val = last_seen;
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            faults++;
        }
    }
    
    if(mode == 1) cout << "Total Page Faults (LRU) = " << faults << endl;
    else cout << "Total Page Faults (Optimal) = " << faults << endl;
}
// ------------------------------------

int main() {
    int pages[50], n, f;

    cout << "Enter number of pages: ";
    cin >> n;
    
    cout << "Enter page reference string:\n";
    for(int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    
    cout << "Enter number of frames: ";
    cin >> f;

    cout << "\n--- Results ---\n";
    fifo(pages, n, f);
    lru_optimal(pages, n, f, 1); // 1 triggers LRU
    lru_optimal(pages, n, f, 2); // 2 triggers Optimal

    return 0;
}
