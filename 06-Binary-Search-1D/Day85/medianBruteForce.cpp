#include <vector>
using namespace std;

class Solution {
public:
    double median(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int m = arr2.size();

        vector<int> merge;
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                merge.push_back(arr1[i]);
                i++;
            } else {
                merge.push_back(arr2[j]);
                j++;
            }
        }

        while (i < n) {
            merge.push_back(arr1[i]);
            i++;
        }

        while (j < m) {
            merge.push_back(arr2[j]);
            j++;
        }

        int p = merge.size();

        if (p % 2 == 0) {
            return (merge[p / 2 - 1] + merge[p / 2]) / 2.0;
        } else {
            return merge[p / 2];
        }
    }
};