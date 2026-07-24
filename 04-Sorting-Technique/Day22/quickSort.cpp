#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:

    int partition(vector<int>& nums, int low, int high) {

        int pivot = nums[high];
        int i = low - 1;

        for(int j = low; j < high; j++) {

            if(nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[i + 1], nums[high]);

        return i + 1;
    }

    void helper(vector<int>& nums, int low, int high) {

        if(low < high) {

            int pIndex = partition(nums, low, high);

            helper(nums, low, pIndex - 1);

            helper(nums, pIndex + 1, high);
        }
    }

public:

    vector<int> quickSort(vector<int>& nums) {

        helper(nums, 0, nums.size() - 1);

        return nums;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;

    vector<int> result = obj.quickSort(nums);

    for(int x : result)
        cout << x << " ";

    return 0;
}