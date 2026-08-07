#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
       for(int i=0; i<nums.size()-1; i++){
         for(int j=i+1; j<nums.size(); j++){
           if(nums[i]+nums[j]==target) return{i,j};
       } 
       } 
       return {};
    }
};

int main(){
    Solution obj;
    int n;cin>>n;
    int target;cin>>target;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> ans = obj.twoSum(arr,target);

      if (ans.empty()) {
        cout << "No Solution";
    } else {
        cout << ans[0] << " " << ans[1];
    }
}