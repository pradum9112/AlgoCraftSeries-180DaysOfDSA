#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {

        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if ((long long)nums[i] > 2LL * nums[j]) {
                    count++;
                }
            }
        }

        return count;
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

    cout << obj.reversePairs(nums) << endl;

    return 0;
}