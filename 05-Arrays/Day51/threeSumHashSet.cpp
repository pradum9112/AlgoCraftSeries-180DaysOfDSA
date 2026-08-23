#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            unordered_set<int> hashset;

            for (int j = i + 1; j < n; j++) {

                int third = -(nums[i] + nums[j]);

                // Check whether required third element exists
                if (hashset.find(third) != hashset.end()) {

                    vector<int> temp = {
                        nums[i],
                        nums[j],
                        third
                    };

                    sort(temp.begin(), temp.end());

                    st.insert(temp);
                }

                hashset.insert(nums[j]);
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
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

    vector<vector<int>> result = obj.threeSum(nums);

    for (auto triplet : result) {

        for (int x : triplet) {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}