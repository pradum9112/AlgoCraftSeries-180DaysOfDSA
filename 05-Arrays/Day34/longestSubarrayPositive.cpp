#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {

        int left = 0;
        int right = 0;
        int sum = 0;
        int maxLen = 0;

        while (right < nums.size()) {

            sum += nums[right];

            while (left <= right && sum > k) {
                sum -= nums[left];
                left++;
            }

            if (sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
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