#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfInversions(vector<int> nums) {

        int n = nums.size();
        long long count = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if (nums[i] > nums[j]) {
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

    cout << obj.numberOfInversions(nums) << endl;

    return 0;
}