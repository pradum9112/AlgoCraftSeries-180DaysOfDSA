#include <iostream>
#include<unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> CountFrequency(vector<int>& nums)
    {
        vector<vector<int>> ans;
        unordered_map<int,int>mpp;
        for(int i : nums) mpp[i]++;
        
        for (auto it: mpp) ans.push_back({it.first,it.second});
        

        return ans;
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
    vector<vector<int>> result = obj.CountFrequency(arr);

    for (auto res : result)
    {
        cout << res[0] <<" "<< res[1] << endl;
    }
    return 0;
}
