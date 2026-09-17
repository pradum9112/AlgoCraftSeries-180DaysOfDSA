#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            // Minimum right half mein hai
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Minimum mid ya left half mein hai
            else {
                high = mid;
            }
        }

        return low;
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