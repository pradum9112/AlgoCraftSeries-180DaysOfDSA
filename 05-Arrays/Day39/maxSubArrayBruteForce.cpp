#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++) {

            int currentSum = 0;

            for (int j = i; j < n; j++) {

                currentSum += nums[j];

                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
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

    cout << obj.maxSubArray(nums);

    return 0;
}