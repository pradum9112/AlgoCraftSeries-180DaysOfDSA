#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        //your code goes here
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==target) return i;
        }
        return -1;
    }
};
int main() {

    int n, target;
    cin >> n;
    cin >> target;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

     int result =  obj.linearSearch(nums, target);

     cout<< result;
    return 0;
}