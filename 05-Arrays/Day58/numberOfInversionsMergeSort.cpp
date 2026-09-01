#include <bits/stdc++.h>
using namespace std;

class Solution {

private:

    long long merge(vector<int>& nums, int low, int mid, int high) {

        vector<int> temp;

        int left = low;
        int right = mid + 1;

        long long count = 0;

        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right]) {

                temp.push_back(nums[left]);
                left++;

            }
            else {

                // nums[left ... mid] are all greater than nums[right]
                count += (mid - left + 1);

                temp.push_back(nums[right]);
                right++;
            }
        }

        // Remaining left elements
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // Remaining right elements
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy sorted elements back
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return count;
    }


    long long mergeSort(vector<int>& nums, int low, int high) {

        long long count = 0;

        if (low >= high) {
            return count;
        }

        int mid = low + (high - low) / 2;

        // Left half
        count += mergeSort(nums, low, mid);

        // Right half
        count += mergeSort(nums, mid + 1, high);

        // Merge + count cross inversions
        count += merge(nums, low, mid, high);

        return count;
    }


public:

    long long numberOfInversions(vector<int> nums) {

        int n = nums.size();

        return mergeSort(nums, 0, n - 1);
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

    cout << obj.numberOfInversions(nums) << endl;

    return 0;
}