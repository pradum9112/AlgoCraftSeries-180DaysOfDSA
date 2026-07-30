#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {

        int n = nums.size();

        if (n <= 1) return;

        k = k % n;

        while (k > 0) {

            int temp = nums[0];

            for (int i = 0; i < n - 1; i++) {
                nums[i] = nums[i + 1];
            }

            nums[n - 1] = temp;

            k--;
        }
    }
};

int main() {

    int n, k;
    cin >> n;
    cin >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    obj.rotateArray(nums, k);

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}