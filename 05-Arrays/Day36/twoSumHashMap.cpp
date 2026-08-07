#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>mp;
       for(int i=0; i<nums.size(); i++){
           int complement = target - nums[i];
           if(mp.count(complement)) return{mp[complement],i};
           mp[nums[i]] = i;
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