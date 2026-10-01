#include <vector>
using namespace std;

class Solution {
public:
    double median(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int m = arr2.size();

        int p = n + m;
        int ind2 = p / 2;
        int ind1 = ind2 - 1;

        int count = 0;
        int ind1el = -1, ind2el = -1;

        int i = 0, j = 0;

        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                if (count == ind1) ind1el = arr1[i];
                if (count == ind2) ind2el = arr1[i];

                count++;
                i++;
            } else {
                if (count == ind1) ind1el = arr2[j];
                if (count == ind2) ind2el = arr2[j];

                count++;
                j++;
            }
        }

        while (i < n) {
            if (count == ind1) ind1el = arr1[i];
            if (count == ind2) ind2el = arr1[i];

            count++;
            i++;
        }

        while (j < m) {
            if (count == ind1) ind1el = arr2[j];
            if (count == ind2) ind2el = arr2[j];

            count++;
            j++;
        }

        if (p % 2 == 1) {
            return ind2el;
        } else {
            return (double)(ind1el + ind2el) / 2.0;
        }
    }
};