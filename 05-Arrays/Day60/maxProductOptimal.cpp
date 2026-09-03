#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        long long maxProd = nums[0];
        long long minProd = nums[0];
        long long result = nums[0];

        for (int i = 1; i < n; i++) {

            // Negative number maximum ko minimum
            // aur minimum ko maximum bana sakta hai.
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }

            maxProd = max(
                (long long)nums[i],
                maxProd * nums[i]
            );

            minProd = min(
                (long long)nums[i],
                minProd * nums[i]
            );

            result = max(result, maxProd);
        }

        return (int)result;
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