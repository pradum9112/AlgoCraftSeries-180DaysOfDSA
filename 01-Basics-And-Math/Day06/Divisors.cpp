#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{ 
    public:
       vector<int>Divisors(int n){
        vector<int> div;
          for(int i=1; i*i<=n;i++){
            if(n%i==0){
               div.push_back(i);
               if(i!=n/i){
                div.push_back(n/i);
               }
            }
          }
          sort(div.begin(),div.end());
          return div;
       }
};

int main(){
    int n;
    cin>>n;
    Solution obj;
    vector<int> ans = obj.Divisors(n);
    for(int x:ans){
       cout<<x<<" ";
    }
    
    return 0;
}