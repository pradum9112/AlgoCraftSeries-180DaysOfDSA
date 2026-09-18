#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for (int num : nums) {
            mpp[num]++;
        }

        for (auto it : mpp) {
            if (it.second == 1) {
                return it.first;
            }
        }

        return -1;
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

    cout << obj.singleNonDuplicate(nums) << endl;

    return 0;
}