#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int n = nums.size();
       int  max_count = 0;
       int count=0;
       for(int i=0;i<n; i++){
        if(nums[i]==1) {
            count++;
            max_count = max(max_count, count);
            }
        else{
            count=0;
        }
       }
       return max_count;
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

     int result =  obj.findMaxConsecutiveOnes(nums);

     cout<< result;
    return 0;
}