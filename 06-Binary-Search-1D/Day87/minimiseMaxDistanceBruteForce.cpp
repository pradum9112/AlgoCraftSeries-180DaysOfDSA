#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        
        // Step 1: Ek array jo track karega ki kis gap mein kitne naye pumps lage
        vector<int> howMany(n - 1, 0);
        
        // Step 2: Ek-ek karke k pumps lagana
        for (int station = 1; station <= k; station++) {
            long double maxSection = -1.0;
            int maxIndex = -1;
            
            // Fretboard (array) par check karo sabse bada gap kahan hai
            for (int i = 0; i < n - 1; i++) {
                long double diff = arr[i + 1] - arr[i];
                // Formula: Original Gap / (Usme pehle se dale pumps + 1)
                long double sectionLength = diff / (howMany[i] + 1.0);
                
                if (sectionLength > maxSection) {
                    maxSection = sectionLength;
                    maxIndex = i;
                }
            }
            
            // Step 3: Sabse bade gap mein apna naya pump thokh do!
            howMany[maxIndex]++;
        }
        
        // K pumps lag chuke hain. Ab dekho final "Max Gap" kitna bacha hai
        long double maxAns = -1.0;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (howMany[i] + 1.0);
            maxAns = max(maxAns, sectionLength);
        }
        
        return maxAns;
    }
};