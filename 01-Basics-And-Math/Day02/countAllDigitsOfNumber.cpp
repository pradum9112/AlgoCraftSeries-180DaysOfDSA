
#include<iostream>
using namespace std;
class Solution{

    public:
           int CountAllDigits(int n){
            int count = 0;
            while(n>0){
                count++;
                n = n/10;
            }
            return count;
           }
    
};

int main()
{
    int n;
    cin>>n;
    Solution obj;
    int countDigits = obj.CountAllDigits(n);
    cout<<countDigits;
    return 0;
}