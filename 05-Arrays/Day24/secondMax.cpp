#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int n = nums.size();

        int maxElement = nums[0];
        int secondMax = -1;

        for (int i = 0; i < n; i++) {

            if (nums[i] > maxElement) {
                secondMax = maxElement;
                maxElement = nums[i];
            }

            else if (nums[i] < maxElement && nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }

        return secondMax;
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

    cout << obj.secondLargestElement(nums);

    return 0;
}