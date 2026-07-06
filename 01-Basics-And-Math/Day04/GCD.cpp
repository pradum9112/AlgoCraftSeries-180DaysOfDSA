#include<iostream>
using namespace std;

class Solution{
   public:
        int GCD(int n1 , int n2){
            while(n2!=0){
                int remainder = n1%n2;
                n1=n2;
                n2=remainder;
            }
            return n1;
        }
};

int main(){
    int n1,n2;
    cin>>n1>>n2;
    Solution obj;
    
    cout<<obj.GCD(n1,n2);

    return 0;
}