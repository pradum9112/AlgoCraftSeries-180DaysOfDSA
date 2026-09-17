#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int>& nums) {
        int n = nums.size();
        //Agli baar Dhyan dena i <n-1;
        //N tak last iteration par nums[n] access hoga, jo out of bounds ha
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return i + 1;
            }
        }

        return 0;
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