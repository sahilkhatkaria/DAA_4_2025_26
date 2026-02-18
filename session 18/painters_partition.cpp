#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &boards, int k, long long maxlen)
{
    long long sum = 0;
    int painters = 1;

    for (int x : boards)
    {
        if (sum + x <= maxlen)
        {
            sum += x;
        }
        else
        {
            painters++;
            sum = x;

            if (painters > k)
                return false;
        }
    }
    return true;
}

int painter_partition(vector<int> &boards, int k)
{
    long long left = 0;
    long long right = 0;

    for (int x : boards)
    {
        left = max(left, (long long)x); 
        right += x;                     
    }

    long long ans = right;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        if (possible(boards, k, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return (int)ans;
}

int main()
{

    vector<int> boards = {10,20,30,40};
    int k = 2;
    cout << painter_partition(boards, k) << endl;

    return 0;
}