#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

class Solution{
public:
       vector<vector<int>>mergeOverlap(vector<vector<int>> &arr){
        int n = arr.size();
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++){
            int start = arr[i][0];
            int end = arr[i][1];
            if(!ans.empty() && end <= ans.back()[1]) continue;
            for(int j=i+1; j<n; j++){
                if(arr[j][0]<= end)
                end = max(end,arr[j][1]);
            }
            ans.push_back({start,end});
        }
        return ans;
      }

};

int main(){
    int n; cin>>n;
    vector<vector<int>> arr(n,vector<int>(2));

    for(int i=0; i<n; i++){
        cin>>arr[i][0]>>arr[i][1];
    }

    Solution obj;

    vector<vector<int>> result = obj.mergeOverlap(arr);

    for(auto interval : result){
        cout<<interval[0]<<" "<<interval[1];
        cout<<endl;
    }
}