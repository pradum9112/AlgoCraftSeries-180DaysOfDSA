#include<bits/stdc++.h>
using namespace std;

      vector<vector<int>> mergeOverlap(vector<vector<int>> & arr){

        int n = arr.size();
        if(n<=1) return arr;
        sort(arr.begin(),arr.end());

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            int start = arr[i][0];
            int end = arr[i][1];

            if(!ans.empty() && start <= ans.back()[1]){
                end = max(ans.back()[1],end);
                ans.back()[1] = end;
            }else{
               ans.push_back({start,end});
            }
        }
        return ans;

      }


int main(){
   
    int n; cin>>n;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0; i<n; i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    vector<vector<int>> result = mergeOverlap(arr);
    for(auto interval : result){
        cout<<interval[0]<<" "<<interval[1]<<"\n";
    }
}