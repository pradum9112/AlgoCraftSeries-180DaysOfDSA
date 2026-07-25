
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int largestElement(vector<int>& nums) {
            int maxElement = nums[0];
            for (int i=0; i<nums.size(); i++){
                if(nums[i]>=maxElement) maxElement = nums[i];
            }
            return maxElement;
    }
};

int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int result = obj.largestElement(arr);
    cout<<result;
}