#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int BinarySearch(vector<int> &arr, int target){
           int n = arr.size();
           int low = 0, high = n-1;
           while(low<=high){
            int mid = low +(high -low)/2;
            if(arr[mid]==target){
                return mid;
            }else if( arr[mid]>target) mid = high - 1;
            else low = mid+ 1;
           }
           return -1;
      }
};

int main(){
    int n; cin>>n;
    int target; cin>>target;

    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Solution obj;
    int result = obj.BinarySearch(arr,target);
    cout<<result;
}