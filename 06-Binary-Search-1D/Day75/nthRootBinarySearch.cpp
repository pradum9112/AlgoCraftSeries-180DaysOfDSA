#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int func(int mid, int n, int m) {
        long long ans = 1;

        for (int i = 1; i <= n; i++) {
            ans = ans * mid;

            if (ans > m) return 2;
        }

        if (ans == m) return 1;

        return 0;
    }

public:
    int NthRoot(int N, int M) {
        int low = 1;
        int high = M;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int val = func(mid, N, M);

            if (val == 1) return mid;
            else if (val == 2) high = mid - 1;
            else low = mid + 1;
        }

        return -1;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    Solution obj;
    cout << obj.NthRoot(N, M) << endl;

    return 0;
}