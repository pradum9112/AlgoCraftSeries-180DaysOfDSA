#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();

        vector<int> merge;

        int i = 0, j = 0;

        while (i < n && j < m) {
            if (a[i] <= b[j]) {
                merge.push_back(a[i]);
                i++;
            } else {
                merge.push_back(b[j]);
                j++;
            }
        }

        while (i < n) {
            merge.push_back(a[i]);
            i++;
        }

        while (j < m) {
            merge.push_back(b[j]);
            j++;
        }

        return merge[k - 1];
    }
};