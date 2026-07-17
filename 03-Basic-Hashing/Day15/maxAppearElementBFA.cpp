#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int mostFrequentElement(vector<int> &nums)
    {
        
        int n = nums.size();
        int max_appear = 0;
        int result = -1;
        for (int i = 0; i<n; i++){
            int count = 0;
            for(int j = 0; j<n; j++){
                if(nums[j]==nums[i]){
                    count++;
                }
            }

            if(count>max_appear){
                max_appear = count;
                result = nums[i];
            }else if(count==max_appear){
                if(nums[i]<result) result = nums[i];
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