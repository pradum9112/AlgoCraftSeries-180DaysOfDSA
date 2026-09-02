#include <bits/stdc++.h>
using namespace std;

class Solution {

private:

    // Count cross reverse pairs
    int countPairs(vector<int>& nums, int low, int mid, int high) {

        int right = mid + 1;
        int count = 0;

        for (int i = low; i <= mid; i++) {

            while (right <= high &&
                   (long long)nums[i] > 2LL * nums[right]) {
                right++;
            }

            count += right - (mid + 1);
        }

        return count;
    }


    // Merge two sorted halves
    void merge(vector<int>& nums, int low, int mid, int high) {

        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right]) {

                temp.push_back(nums[left]);
                left++;

            } else {

                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }


    int mergeSort(vector<int>& nums, int low, int high) {

        if (low >= high) {
            return 0;
        }

        int mid = low + (high - low) / 2;

        int count = 0;

        // Count reverse pairs in left half
        count += mergeSort(nums, low, mid);

        // Count reverse pairs in right half
        count += mergeSort(nums, mid + 1, high);

        // Count cross reverse pairs
        count += countPairs(nums, low, mid, high);

        // Merge both sorted halves
        merge(nums, low, mid, high);

        return count;
    }


public:

    int reversePairs(vector<int>& nums) {

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

    cout << obj.reversePairs(nums) << endl;

    return 0;
}