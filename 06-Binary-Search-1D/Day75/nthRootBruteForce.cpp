#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int NthRoot(int N, int M) {
        for (int i = 1; i <= M; i++) {
            long long ans = 1;

            for (int j = 1; j <= N; j++) {
                ans = ans * i;

                if (ans > M) break;
            }

            if (ans == M) return i;
            if (ans > M) break;
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