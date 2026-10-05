#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int> &a, int maxSumLimit) {
        int subarrays = 1;
        long long currentSum = 0;

        for (int i = 0; i < a.size(); i++) {
            if (currentSum + a[i] <= maxSumLimit) {
                currentSum += a[i];
            } else {
                subarrays++;
                currentSum = a[i];
            }
        }

        return subarrays;
    }

    int largestSubarraySumMinimized(vector<int> &a, int k) {
        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int totalSubarrays = countSubarrays(a, mid);

            if (totalSubarrays <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};