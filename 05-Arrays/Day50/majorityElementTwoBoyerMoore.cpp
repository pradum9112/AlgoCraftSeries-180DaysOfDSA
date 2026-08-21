#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {

        int cnt1 = 0;
        int cnt2 = 0;

        int el1 = INT_MIN;
        int el2 = INT_MIN;

        // --------------------------------
        // Step 1: Find possible candidates
        // --------------------------------
        for (int num : nums) {

            if (cnt1 == 0 && num != el2) {

                cnt1 = 1;
                el1 = num;

            }
            else if (cnt2 == 0 && num != el1) {

                cnt2 = 1;
                el2 = num;

            }
            else if (num == el1) {

                cnt1++;

            }
            else if (num == el2) {

                cnt2++;

            }
            else {

                cnt1--;
                cnt2--;
            }
        }

        // --------------------------------
        // Step 2: Verify candidates
        // --------------------------------
        cnt1 = 0;
        cnt2 = 0;

        for (int num : nums) {

            if (num == el1) {
                cnt1++;
            }
            else if (num == el2) {
                cnt2++;
            }
        }

        // --------------------------------
        // Step 3: Store valid candidates
        // --------------------------------
        vector<int> ans;

        int mini = nums.size() / 3;

        if (cnt1 > mini) {
            ans.push_back(el1);
        }

        if (cnt2 > mini) {
            ans.push_back(el2);
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