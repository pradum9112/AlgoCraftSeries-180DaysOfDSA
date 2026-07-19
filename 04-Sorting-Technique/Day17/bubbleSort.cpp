#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> bubbleSort(vector<int>& nums) {
        bool swapped = false;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size()-i-1; j++){
                if(nums[j]>nums[j+1]){
                 swap(nums[j],nums[j+1]);
                 swapped = true;
                 }
            }
            if(!swapped) break;
        }
        return nums;
    }
};


int main(){
    int n; 
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Solution obj;
    obj.bubbleSort(arr);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}