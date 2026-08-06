#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {

            int sum = 0;

            for (int j = i; j < n; j++) {

                sum += nums[j];

                if (sum == k) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;

    cout << obj.longestSubarray(nums, k);

    return 0;
}