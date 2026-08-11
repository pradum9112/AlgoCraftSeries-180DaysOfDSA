#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int stockBuySell(vector<int> arr, int n) {

        int minPrice = arr[0];
        int maxProfit = 0;

        for (int i = 0; i < n; i++) {

            // Minimum price found so far
            minPrice = min(minPrice, arr[i]);

            // Profit if we sell today
            int currentProfit = arr[i] - minPrice;

            // Store maximum profit
            maxProfit = max(maxProfit, currentProfit);
        }

        return maxProfit;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    cout << obj.stockBuySell(arr, n);

    return 0;
}