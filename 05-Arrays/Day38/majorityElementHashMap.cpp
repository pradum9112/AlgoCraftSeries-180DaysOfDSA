#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> mpp;

        for (int num : nums) {

            mpp[num]++;

            if (mpp[num] > n / 2) {
                return num;
            }
        }

        return -1;
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

    cout << obj.majorityElement(nums);

    return 0;
}