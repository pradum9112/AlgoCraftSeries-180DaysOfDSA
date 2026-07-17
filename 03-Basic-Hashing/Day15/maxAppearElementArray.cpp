#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int mostFrequentElement(vector<int> &nums)
    {
        
        vector<int>freq(10001,0);
        for (int num : nums) freq[num]++;
        int max_appear = 0;
        int result = -1;
        for (int i = 1; i<=10000; i++)
        {
            if (freq[i] > max_appear)
            {
                max_appear = freq[i];
                result = i;
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