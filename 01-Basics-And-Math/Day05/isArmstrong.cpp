#include<iostream>
#include<cmath>
using namespace std;

class Solution{
    public:
       bool isArmstrong(int n){
        int temp = n;
        int digitCount=0;
        if(temp == 0){
            digitCount =1;
        }else{
            while(temp>0){
                temp/=10;
                digitCount++;
            }
        }

        temp = n;
        int digitSum = 0;
        int lastDigit = 0;
        while(temp>0){
            lastDigit =temp % 10;
            temp /=10;
            digitSum += round(pow(lastDigit,digitCount));
        }
        return digitSum == n;
       }


};

int main(){
    int n;
    cin>>n;
    Solution obj;
    cout<<boolalpha<<obj.isArmstrong(n);
}