#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                set<long long> hashset;

                for (int k = j + 1; k < n; k++) {

                    long long sum =
                        (long long)nums[i] +
                        nums[j] +
                        nums[k];

                    long long fourth = (long long)target - sum;

                    if (hashset.find(fourth) != hashset.end()) {

                        vector<int> temp = {
                            nums[i],
                            nums[j],
                            nums[k],
                            (int)fourth
                        };

                        sort(temp.begin(), temp.end());

                        st.insert(temp);
                    }

                    hashset.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};

int main() {

    int n, target;
    cin >> n >> target;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    vector<vector<int>> result = obj.fourSum(nums, target);

    for (auto quad : result) {

        for (int x : quad) {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}