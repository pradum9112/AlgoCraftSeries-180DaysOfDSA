#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortZeroOneTwo(vector<int> &nums)
    {

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high)
        {

            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if (nums[mid] == 1)
            {
                mid++;
            }

            else
            { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main()
{

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;

    obj.sortZeroOneTwo(nums);

    for (int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}

/* 2. Better Approach: Counting / Frequency MapConcept: Iterate through the array 
once to count the frequency of 0s, 1s, and 2s. Then, overwrite the array in order 
with the calculated counts.Time Complexity: $\mathcal{O}(N) + \mathcal{O}(N) = \mathcal{O}(2N)
 \approx \mathcal{O}(N)$ — Two passes.Space Complexity: $\mathcal{O}(1)$ — In-place.
*/

// class Solution {
// public:
//     void sortZeroOneTwo(vector<int>& nums) {
//         int count0 = 0, count1 = 0, count2 = 0;

//         // Pass 1: Count occurrences
//         for (int num : nums) {
//             if (num == 0) count0++;
//             else if (num == 1) count1++;
//             else count2++;
//         }

//         // Pass 2: Overwrite the array
//         int idx = 0;
//         while (count0--) nums[idx++] = 0;
//         while (count1--) nums[idx++] = 1;
//         while (count2--) nums[idx++] = 2;
//     }
// };