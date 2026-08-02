#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> unionArr;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;

        // 1. Traverse both arrays simultaneously
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                // Check if element is unique before pushing
                if (unionArr.empty() || unionArr.back() != nums1[i]) {
                    unionArr.push_back(nums1[i]);
                }
                if (nums1[i] == nums2[j]) {
                    j++; // Dono equal hain toh j ko bhi aage badao
                }
                i++;
            } else {
                if (unionArr.empty() || unionArr.back() != nums2[j]) {
                    unionArr.push_back(nums2[j]);
                }
                j++;
            }
        }

        // 2. Agar nums1 me elements bache hain
        while (i < n) {
            if (unionArr.empty() || unionArr.back() != nums1[i]) {
                unionArr.push_back(nums1[i]);
            }
            i++;
        }

        // 3. Agar nums2 me elements bache hain
        while (j < m) {
            if (unionArr.empty() || unionArr.back() != nums2[j]) {
                unionArr.push_back(nums2[j]);
            }
            j++;
        }

        return unionArr;
    }
};

int main() {

    int n, m;
    cin >> n;
    cin >> m;

    vector<int> nums1(n);
    vector<int> nums2(m);

    for (int i = 0; i < n; i++) 
        cin >> nums1[i];

    for (int i = 0; i < m; i++) 
        cin >> nums2[i];
    

    Solution obj;

     vector<int>UnionArray =  obj.unionArray(nums1,nums2);

      for (int x : UnionArray)
          cout << x << " ";
    return 0;
}