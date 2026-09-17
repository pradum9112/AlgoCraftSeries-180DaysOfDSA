#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int>& nums) {
        int n = nums.size();

        int minValue = nums[0];
        int minIndex = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < minValue) {
                minValue = nums[i];
                minIndex = i;
            }
        }

        return minIndex;
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

    cout << obj.findKRotation(nums) << endl;

    return 0;
}