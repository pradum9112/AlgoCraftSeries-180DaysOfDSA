#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = 0;

        for (int num : nums) {
            ans ^= num;
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

    int ans = obj.singleNumber(nums);

    cout << ans;

    return 0;
}