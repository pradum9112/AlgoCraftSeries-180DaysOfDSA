#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
    public:
      
      void helper(int arr[],int l,int r){
        if(l>=r) return;
        swap(arr[l],arr[r]);
        helper(arr,l+1,r-1);
      }
      void reverse(int arr[],int n){
         helper(arr,0,n-1);
      }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
       cin>>arr[i]; 
    }
    Solution obj;
    obj.reverse(arr,n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}