#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int left = m - 1;
        int right = 0;

        // nums1 ke largest valid element ko
        // nums2 ke smallest element se compare karo
        while (left >= 0 && right < n) {

            if (nums1[left] > nums2[right]) {

                swap(nums1[left], nums2[right]);

                left--;
                right++;
            }
            else {
                break;
            }
        }

        // Dono arrays ko individually sort karo
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());
    }
};

int main() {

    int m, n;
    cin >> m >> n;

    vector<int> nums1(m);
    vector<int> nums2(n);

    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    Solution obj;

    obj.merge(nums1, m, nums2, n);

    cout << "nums1: ";

    for (int x : nums1) {
        cout << x << " ";
    }

    cout << endl;

    cout << "nums2: ";

    for (int x : nums2) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}