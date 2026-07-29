#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {

        int n = nums.size();

        if (n <= 1) return;

        int temp = nums[0];

        for (int i = 0; i < n - 1; i++) {
            nums[i] = nums[i + 1];
        }

        nums[n - 1] = temp;
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

    obj.rotateArrayByOne(nums);

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}