#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> FrequencyCounting(int n, int arr[], int q, int queries[]) {
            vector<int>ans;
            for(int i=0; i<q; i++){
                int cnt = 0;
                for(int j=0; j<n; j++){
                
                    if(arr[j]==queries[i]) cnt++;
            }
            ans.push_back(cnt);
            }

        return ans;
        }
};



int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int q;
    cin >> q;
    int queries[q];
    for(int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    Solution obj;
    vector<int> result = obj.FrequencyCounting(n, arr, q, queries);

    for(int res : result) {
        cout << res << endl;
    }
    return 0;
}