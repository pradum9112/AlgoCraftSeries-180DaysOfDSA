#include<iostream>
using namespace std;

class Solution {
public:
    int factorial(int n) {
      if(n==0) return 1;
      return n * factorial(n-1);
    }
};


int main(){
    int n;
    cin>>n;
    Solution obj;
    cout<<obj.factorial(n);
    return 0;
}
