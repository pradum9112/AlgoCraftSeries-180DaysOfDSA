#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {

            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if (nums[mid] == 1) {
                mid++;
            }

            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
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

    obj.sortZeroOneTwo(nums);

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}