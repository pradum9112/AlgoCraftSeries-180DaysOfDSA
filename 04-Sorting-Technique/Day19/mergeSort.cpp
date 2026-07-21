#include <iostream>
#include <vector>

using namespace std;

class Solution {
private: 
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

   
        while (right <= high) {
            temp.push_back(nums[right++]);
        }


        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    void mergeSortHelper(vector<int>& nums, int low, int high) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;

        mergeSortHelper(nums, low, mid);       
        mergeSortHelper(nums, mid + 1, high); 
        merge(nums, low, mid, high);  
    }

public:
    vector<int> mergeSort(vector<int>& nums) {
        if (nums.empty()) return nums;
        mergeSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
};


int main() {
    Solution sol;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    vector<int> sortedNums = sol.mergeSort(nums);

    for (int val : sortedNums) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}