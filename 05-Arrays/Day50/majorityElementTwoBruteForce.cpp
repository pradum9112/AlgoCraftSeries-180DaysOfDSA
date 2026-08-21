#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            // Check whether this element is already added
            if (ans.empty() || ans[0] != nums[i]) {

                int cnt = 0;

                for (int j = 0; j < n; j++) {
                    if (nums[j] == nums[i]) {
                        cnt++;
                    }
                }

                if (cnt > n / 3) {
                    ans.push_back(nums[i]);
                }
            }

            // At most 2 elements can occur more than n/3 times
            if (ans.size() == 2) {
                break;
            }
        }

        return ans;
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

    vector<int> result = obj.majorityElementTwo(nums);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}