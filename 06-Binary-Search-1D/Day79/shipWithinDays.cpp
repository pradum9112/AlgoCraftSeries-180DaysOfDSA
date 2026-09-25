#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int calculated_days(vector<int>& packagesWeights, int capacity) {
        int shipWithinDays = 0;
        int countDays = 1;

        for (int i = 0; i < packagesWeights.size(); i++) {
            if (shipWithinDays + packagesWeights[i] > capacity) {
                countDays++;
                shipWithinDays = packagesWeights[i];
            } else {
                shipWithinDays += packagesWeights[i];
            }
        }

        return countDays;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int max_val = *max_element(weights.begin(), weights.end());

        int sum_val = 0;
        for (int weight : weights) {
            sum_val += weight;
        }

        for (int capacity = max_val; capacity <= sum_val; capacity++) {
            if (calculated_days(weights, capacity) <= days) {
                return capacity;
            }
        }

        return -1;
    }
};