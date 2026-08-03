#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> mp;

        // Count frequency of each element
        for (int num : nums) {
            mp[num]++;
        }

        // Find the element whose frequency is 1
        for (auto it : mp) {
            if (it.second == 1) {
                return it.first;
            }
        }

        return -1; // Safety return (Problem guarantees one unique element)
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