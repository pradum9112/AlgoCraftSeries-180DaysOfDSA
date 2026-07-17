#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int mostFrequentElement(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        for (int i : nums)
            mpp[i]++;
        int max_appear = 0;
        int result = -1;
        for (auto it : mpp)
        {
            if (it.second > max_appear)
            {
                max_appear = it.second;
                result = it.first;
            }
            else if (it.second == max_appear)
            {
                if (it.first < result)
                    result = it.first;
            }
        }
        return result;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    int result = obj.mostFrequentElement(arr);
    cout << result;
}