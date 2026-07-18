#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> selectionSort(vector<int>& nums) {
       int n = nums.size();
       for(int i=0; i<n; i++){
        int mi = i;
          for(int j = i+1; j<n; j++){
            if(nums[j]<nums[mi]) mi=j;
          }
          if(mi!=i) swap(nums[i],nums[mi]);
       }
       return nums;
    }
};

int main(){
    int n; 
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    Solution obj;
    vector<int> result = obj.selectionSort(arr);
    for(auto i : result) cout<< i<<" ";
}