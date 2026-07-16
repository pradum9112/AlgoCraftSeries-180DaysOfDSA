#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> CountFrequency(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<bool> visited(n,false);
        for (int i = 0; i < n; i++)
        {
            if(visited[i] == true) continue;
            int count = 1;
            for (int j = i+1; j < n; j++)
            {
                if(nums[i]==nums[j]){
                visited[j]=true;
                count++;   }
            }
            ans.push_back({nums[i], count});
        }

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
