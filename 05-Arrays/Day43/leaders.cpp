#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {

        vector<int> result;

        int n = nums.size();

        int maxFromRight = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {

            if (nums[i] > maxFromRight) {

                result.push_back(nums[i]);

                maxFromRight = nums[i];
            }
        }

        reverse(result.begin(), result.end());

        return result;
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

    vector<int> result = obj.leaders(nums);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}