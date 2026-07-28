#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        if (n <= 2) return 2;

        int i = 2;
        
        for (int j = 2; j < n; j++) {

          if (nums[j] != nums[i-2]) {
              nums[i] = nums[j];
              i++;
            }

        }

        return i;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    int k = obj.removeDuplicates(nums);

    cout << "Length = " << k << endl;

    cout << "Array = ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}