#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void helper(vector<int>& nums, int n) {

        if(n <= 1)
            return;

        helper(nums, n - 1);

        int key = nums[n - 1];
        int j = n - 2;

        while(j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = key;
    }

public:
    vector<int> insertionSort(vector<int>& nums) {

        int n = nums.size();

        helper(nums, n);

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

    vector<int> result = obj.insertionSort(nums);

    for(int x : result)
        cout << x << " ";

    return 0;
}