#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& C, long long max_capacity, int A) {
        int paintersUsed = 1;
        long long current_boards_sum = 0;

        for (int i = 0; i < C.size(); i++) {
            if (current_boards_sum + C[i] > max_capacity) {
                paintersUsed++;
                current_boards_sum = C[i];

                if (paintersUsed > A)
                    return false;
            } else {
                current_boards_sum += C[i];
            }
        }

        return true;
    }

    int paint(int A, int B, vector<int>& C) {
        long long low = 0;
        long long high = 0;

        for (int board : C) {
            low = max(low, (long long)board);
            high += board;
        }

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isPossible(C, mid, A)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        long long final_ans =
            ((ans % 10000003) * B) % 10000003;

        return final_ans;
    }
};