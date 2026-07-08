#include<iostream>

using namespace std;

class Solution{ 
    public:
       int SquareRoot(int n){
        
          for(int i=1; i*i<=n;i++){
            if(i*i==n) return i;
    };
 }
};

int main(){
    int n;
    cin>>n;
    Solution obj;
    cout<<obj.SquareRoot(n);
      
    return 0;
}