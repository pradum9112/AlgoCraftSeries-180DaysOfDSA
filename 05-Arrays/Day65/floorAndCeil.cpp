#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n = nums.size();

        int floorVal = -1;
        int ceilVal = -1;

        for (int i = 0; i < n; i++) {

            // Floor: largest value <= x
            if (nums[i] <= x) {
                floorVal = nums[i];
            }

            // Ceil: smallest value >= x
            if (nums[i] >= x && ceilVal == -1) {
                ceilVal = nums[i];
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