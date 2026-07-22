#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:    
    void bubbleSortHelper(vector<int> & nums, int n){
        if(n<=1) return;
        for(int i = 0; i<n-1; i++){
            if(nums[i]>nums[i+1]) swap(nums[i],nums[i+1]);
        }
         bubbleSortHelper(nums,n-1);
    }
public:
    vector<int> recursiveBubbleSort(vector<int>& nums) {
        int n = nums.size();
        bubbleSortHelper(nums,n);
        return nums;
    }
};

int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    vector<int> result = obj.recursiveBubbleSort(nums);
    for(auto it : result){
        cout<<it<< " ";
    }
}
