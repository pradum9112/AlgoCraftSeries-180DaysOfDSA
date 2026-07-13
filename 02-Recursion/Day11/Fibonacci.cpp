// #include<iostream>
// using namespace std;

// class Solution {
// public:
//     int fib(int n) {
//         //your code goes here
//         if(n==0) return 0;
//         if(n==1) return 1;
//         int a = 0;
//         int b = 1;
//         while(--n){
//             int c = a+b;
//             a=b;
//             b=c;
//         }
//         return b;
//     }
// };

// int main(){
//     int n;
//     cin>>n;
//     Solution obj;
//     cout<<obj.fib(n);
//     return 0;
// }



#include<iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        //your code goes here
        if(n==0) return 0;
        if(n==1) return 1;
        return fib(n-1) +fib(n-2);
    }
};

int main(){
    int n;
    cin>>n;
    Solution obj;
    cout<<obj.fib(n);
    return 0;
}