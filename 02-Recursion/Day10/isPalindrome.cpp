// #include <iostream>
// #include <string>
// using namespace std;

//  bool isPalindrome(string& s){
//      int start=0;
//      int end = s.length()-1;
//      while(start<end){
//          if(s[start]!= s[end]) return false;
//          start++;
//          end--;
//      }
//      return true;
//  }

// int main()
// {
   
//     string s;
//     if(cin>>s){
        
//     if(isPalindrome(s)) cout<<"true";
//     else cout<<"false";
    
//     }
//     return 0;
// }


// #include <iostream>
// #include <string>
// using namespace std;

// class Solution{
//     public:
//         bool isPalindrome(string& s){
//         int start=0;
//         int end = s.length()-1;
//         while(start<end){
//             if(s[start]!= s[end]) return false;
//             start++;
//             end--;
//         }
//         return true;
//  }
// };
 

// int main()
// {
   
//     string s;
//     Solution obj;

//     if(cin>>s){    
//     if(obj.isPalindrome(s)) cout<<"true";
//     else cout<<"false";
//     }

//     return 0;
// }


#include <iostream>
#include <string>
using namespace std;

class Solution{
    public:
        bool helper(string& s,int start ,int end){
            if(start>=end) return true;
            if(s[start]!=s[end]) return false;
            return helper(s,start+1,end-1); 
        }

        bool isPalindrome(string& s){
        int end = s.length()-1;
        int start=0;
        return helper(s,start,end);    
      
 }
};
 

int main()
{
   
    string s;
    Solution obj;

    if(cin>>s){    
    if(obj.isPalindrome(s)) cout<<"true";
    else cout<<"false";
    }
    
    return 0;
}