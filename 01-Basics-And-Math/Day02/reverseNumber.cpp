#include<iostream>
using namespace std;
class Solution{
   public:
      void reverseNumber(int n){
       int rev_num = 0;
        while(n>0){
           int last_digit = n%10;
            n = n/10;
            rev_num = (rev_num * 10) + last_digit;
        }
        cout<< rev_num;
      }
};

int main()
{
    int n; 
    cin>> n;
    Solution obj;
    obj.reverseNumber(n);

    return 0;
}