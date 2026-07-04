#include <iostream>
#include <algorithm>
using namespace std;
class solution{
    public:
            void pattern22(int n){
            int size = 2*n-1;
            for(int i=0; i<size; i++){
                for(int j=0; j<size;j++){
                    int top = i;
                    int bottom = (size - 1)- i;
                    int left = j;
                    int right = (size - 1)- j;
                    int min_dist = min({top,bottom,left,right});
                    cout<<(n-min_dist);
                }
                cout<<endl;
            }
            }
};

int main()
{
    int n;
    cin>>n;
    solution obj;
    obj.pattern22(n);

    return 0;
}