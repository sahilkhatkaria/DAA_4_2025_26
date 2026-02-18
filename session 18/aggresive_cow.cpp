#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &stalls, int k, int dist)
{
    int cows = 1; // place first cow
    int last = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - last >= dist)
        {
            cows++;
            last = stalls[i];

            if (cows >= k)
                return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int left = 0;
    int right = stalls.back() - stalls.front();
    int ans = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (possible(stalls, k, mid))
        {
            ans = mid;
            left = mid + 1; 
        }
        else
        {
            right = mid - 1;
        }
    }

    return ans;
}

int main()
{

    vector <int> stalls = {1,2,4,8,9};
    int k = 3;
    aggressiveCows(stalls,k);

    return 0;
}