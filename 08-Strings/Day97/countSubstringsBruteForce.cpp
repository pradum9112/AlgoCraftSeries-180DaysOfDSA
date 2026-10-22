#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubstrings(string s) {
        int n = s.size();
        long long count = 0;

        for (int i = 0; i < n; i++) {
            int freq[10] = {0};
            int oddCount = 0;

            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                freq[idx]++;

                if (freq[idx] % 2 != 0) {
                    oddCount++;
                } else {
                    oddCount--;
                }

                if (oddCount == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution solution;
    cout << solution.countSubstrings("abac") << '\n';
    return 0;
}