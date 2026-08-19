#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                int sum = 0;

                for (int K = i; K <= j; K++) {
                    sum += nums[K];
                }

                if (sum == k) {
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

    cout << obj.subarraySum(nums, k);

    return 0;
}