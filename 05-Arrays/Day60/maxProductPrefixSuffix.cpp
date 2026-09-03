#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        long long pref = 1;
        long long suff = 1;
        long long ans = LLONG_MIN;

        for (int i = 0; i < n; i++) {

            if (pref == 0)
                pref = 1;

            if (suff == 0)
                suff = 1;

            pref *= nums[i];

            suff *= nums[n - i - 1];

            ans = max(ans, max(pref, suff));
        }

        return (int)ans;
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

    cout << obj.maxProduct(nums) << endl;

    return 0;
}