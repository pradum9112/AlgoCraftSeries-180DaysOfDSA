#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int calculated_days(vector<int>& packagesWeights, int capacity) {
        int shipWithinDays = 0;
        int countDays = 1;

        for (int weight : packagesWeights) {
            if (shipWithinDays + weight > capacity) {
                countDays++;
                shipWithinDays = weight;
            } else {
                shipWithinDays += weight;
            }
        }

        return countDays;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());

        int totalSumOfPackages = 0;
        for (int weight : weights) {
            totalSumOfPackages += weight;
        }

        int high = totalSumOfPackages;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (calculated_days(weights, mid) <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};