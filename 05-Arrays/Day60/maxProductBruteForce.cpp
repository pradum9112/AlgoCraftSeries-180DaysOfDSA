#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        long long max_product = nums[0];

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                long long product = 1;

                for (int k = i; k <= j; k++) {
                    product *= nums[k];
                }

                max_product = max(max_product, product);
            }
        }

        return (int)max_product;
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