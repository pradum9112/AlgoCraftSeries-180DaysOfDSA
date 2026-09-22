#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Your code goes here
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dummyRow(n, 0);
        vector<int> dummyCol(m, 0);
        for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
             if(matrix[i][j] == 0) dummyRow[i]=1;
             if(matrix[i][j] == 0) dummyCol[j]=1;
         } 
       }
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
             if(dummyRow[i]==1 || dummyCol[j]==1){
                matrix[i][j]=0;
             }
         } 
       }
    }
};

int main() {
	
	Solution obj;
	int n,m;
	cin>>n>>m;
	vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
             cin>>arr[i][j];
         } 
    }
    
    obj.setZeroes(arr);
   
    for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
             cout<<arr[i][j]<<" ";
         }
         cout<<"\n";
    }
    return 0;
}
