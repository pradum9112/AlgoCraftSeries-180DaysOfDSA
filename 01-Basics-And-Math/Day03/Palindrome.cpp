// #include<iostream>
// using namespace std;

// class Solution {
//     public:
//       bool isPalindrome(int n){
//         long long rev_num = 0;
//         int Num = n;
//         if(n<0) return false;
//         if(n%10==0 && n!=0) return false;
//         while(n>0){
//             int lastDigit = n % 10;
//             n = n/10;
//             rev_num = (rev_num * 10) + lastDigit;
//         }
//         return  Num == rev_num;
//       }
// };

// int main(){
//     int n; 
//     cin>>n;
//     Solution obj;
//     obj.isPalindrome(n);
//     cout<<boolalpha <<obj.isPalindrome(n);

//     return 0;
// }

#include<iostream>
using namespace std;

class Solution {
    public:
      bool isPalindrome(int n){
        int rev_num = 0;
        if(n<0 || (n%10==0 && n!=0)) return false;
        while(n>rev_num){
            rev_num = (rev_num * 10) + n%10;
            n = n/10;
        }
        return  n == rev_num || n== rev_num/10 ;
      }
};

int main(){
    int n; 
    cin>>n;
    Solution obj;
    cout<<boolalpha <<obj.isPalindrome(n);

    return 0;
}