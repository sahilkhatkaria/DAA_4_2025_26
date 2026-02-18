#include <bits/stdc++.h>
using namespace std;

int upperbound(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    int ans = arr.size(); 

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] > target)
        {
            ans = mid;
            right = mid - 1; 
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

int main()
{

    vector<int> arr = {0, 1, 1, 2, 3, 4, 5};
    int res = upperbound(arr,2);
    cout<<res;

    return 0;
}