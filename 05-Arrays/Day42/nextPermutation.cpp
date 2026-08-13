#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Find breakpoint
        int ind = -1;

        for (int i = n - 2; i >= 0; i--) {

            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // Step 2: No breakpoint
        // Array is in descending order
        if (ind == -1) {

            int start = 0;
            int end = n - 1;

            while (start < end) {

                int temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;

                start++;
                end--;
            }

            return;
        }

        // Step 3: Find the element just greater than nums[ind]
        // from the right side and swap
        for (int i = n - 1; i > ind; i--) {

            if (nums[i] > nums[ind]) {

                int temp = nums[i];
                nums[i] = nums[ind];
                nums[ind] = temp;

                break;
            }
        }

        // Step 4: Reverse the suffix
        int start = ind + 1;
        int end = n - 1;

        while (start < end) {

            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;

            start++;
            end--;
        }
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

    obj.nextPermutation(nums);

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}