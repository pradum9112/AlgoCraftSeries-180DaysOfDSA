#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pascalTriangleI(int r, int c) {

        long long res = 1;

        // Convert 1-based row and column
        // into 0-based n and k
        int n = r - 1;
        int k = c - 1;

        // nCk == nC(n-k)
        // Choose the smaller k
        if (k > n - k) {
            k = n - k;
        }

        // Calculate nCk
        for (int i = 0; i < k; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }

        return (int)res;
    }
};

int main() {

    int r, c;
    cin >> r >> c;

    Solution obj;

    cout << obj.pascalTriangleI(r, c);

    return 0;
}