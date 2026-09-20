#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int floorSqrt(int n) {
        int ans = 0;

        for (int i = 1; i * i <= n; i++) {
            ans = i;
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;

    cout << obj.floorSqrt(n) << endl;

    return 0;
}