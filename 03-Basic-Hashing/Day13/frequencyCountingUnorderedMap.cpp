
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> FrequencyCountingOptimized(int n, int arr[], int q, int queries[])
    {
        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
             mpp[arr[i]]++;
        }

        vector<int> ans;
        for (int i = 0; i < q; i++)
        {
            int querynum = queries[i];
             if (mpp.find(querynum) != mpp.end()){    
                 ans.push_back(mpp[querynum]);          
             }else{
                ans.push_back(0);
             } 
         }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int q;
    cin >> q;
    int queries[q];
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i];
    }

    Solution obj;
    vector<int> result = obj.FrequencyCountingOptimized(n, arr, q, queries);

    for (int res : result)
    {
        cout << res << endl;
    }
    return 0;
}