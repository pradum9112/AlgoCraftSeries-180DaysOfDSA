#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> FrequencyCountingOptimized(int n, int arr[], int q, int queries[])
    {
        int max_element = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max_element)
                max_element = arr[i];
        }
        vector<int> hash(max_element+1,0);
        for(int i=0;i<n;i++){
             hash[arr[i]]++;
        }

        vector<int> ans;
        for (int i = 0; i < q; i++)
        {
            int querynum = queries[i];
             if (querynum <= max_element){    
                 ans.push_back(hash[querynum]);          
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

