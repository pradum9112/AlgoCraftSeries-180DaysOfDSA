#include<iostream>
using namespace std;

class Solution {
  public:
    void printNumbers(int n) {
        if(n==0) return;
        printNumbers(n-1);
        cout<<n<<endl;
    }
};

int main(){
    int n;
    cin>>n;
    Solution obj;
    obj.printNumbers(n);
    return 0;
}
