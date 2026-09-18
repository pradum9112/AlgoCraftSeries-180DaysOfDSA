#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n = nums.size();

        int floorVal = -1;
        int ceilVal = -1;

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == x) {
                return {nums[mid], nums[mid]};
            }
            else if (nums[mid] < x) {
                // nums[mid] can be a possible floor
                floorVal = nums[mid];
                low = mid + 1;
            }
            else {
                // nums[mid] can be a possible ceil
                ceilVal = nums[mid];
                high = mid - 1;
            }
        }

        return {floorVal, ceilVal};
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 4, 6, 8};
    int x = 5;

    vector<int> ans = obj.getFloorAndCeil(nums, x);

    cout << "Floor = " << ans[0] << endl;
    cout << "Ceil = " << ans[1] << endl;

    return 0;
}