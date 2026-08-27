#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithXorK(vector<int>& nums, int k) {

        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {

            int current_xr = 0;

            for (int j = i; j < n; j++) {

                current_xr = current_xr ^ nums[j];

                if (current_xr == k) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << obj.subarraysWithXorK(nums, k) << endl;

    return 0;
}