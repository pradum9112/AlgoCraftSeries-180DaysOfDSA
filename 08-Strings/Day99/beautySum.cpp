#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int totalBeauty = 0;

        for (int i = 0; i < n; i++) {
            int freq[26] = {0};

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int maxFreq = 0;
                int minFreq = INT_MAX;

                for (int c = 0; c < 26; c++) {
                    if (freq[c] > 0) {
                        maxFreq = max(maxFreq, freq[c]);
                        minFreq = min(minFreq, freq[c]);
                    }
                }

                totalBeauty += maxFreq - minFreq;
            }
        }

        return totalBeauty;
    }
};

int main() {
    Solution solution;

    cout << solution.beautySum("aabcb") << '\n';
    cout << solution.beautySum("aabcbaa") << '\n';

    return 0;
}