// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     void rotateArray(vector<int>& nums, int k) {

//         int n = nums.size();

//         if (n <= 1) return;

//         k = k % n;

//        reverse(nums.begin(),nums.begin()+k);
//        reverse(nums.begin()+k,nums.end());
//        reverse(nums.begin(),nums.end());

//     }
// };

// int main() {

//     int n, k;
//     cin >> n;
//     cin >> k;

//     vector<int> nums(n);

//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     Solution obj;

//     obj.rotateArray(nums, k);

//     for (int x : nums) {
//         cout << x << " ";
//     }

//     return 0;
// }




#include <iostream>
#include <vector>
using namespace std;

class Solution {

private:

    void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

public:

    void rotateArray(vector<int>& nums, int k) {

        int n = nums.size();
        if (n <= 1) return;
        k = k % n;

        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, n - 1);
        reverseArray(nums, 0, n - 1);

    }

};

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    obj.rotateArray(nums, k);

    for (int x : nums)
        cout << x << " ";

    return 0;
}