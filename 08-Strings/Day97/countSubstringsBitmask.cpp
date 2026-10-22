#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubstrings(string s) {
        long long count = 0;
        int mask = 0;

        unordered_map<int, long long> prefixFreq;
        prefixFreq[0] = 1;

        for (char c : s) {
            int bit = c - 'a';
            mask ^= (1 << bit);

            // Count previous prefix masks differing by one bit.
            for (int b = 0; b < 10; b++) {
                int target = mask ^ (1 << b);

                if (prefixFreq.count(target)) {
                    count += prefixFreq[target];
                }
            }

            prefixFreq[mask]++;
        }

        return count;
    }
};

int main() {
    Solution solution;
    cout << solution.countSubstrings("abac") << '\n';
    return 0;
}