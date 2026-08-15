#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        if (n == 0)
            return 0;

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int num : st) {

            // num is the starting point of a sequence
            if (st.find(num - 1) == st.end()) {

                int currentNum = num;
                int currentStreak = 1;

                while (st.find(currentNum + 1) != st.end()) {

                    currentNum++;
                    currentStreak++;
                }

                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << obj.longestConsecutive(nums);

    return 0;
}