#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfSubarrays(vector<int> &arr, int k)
{
    priority_queue<pair<int,int>> pq;
    vector<int> res;

    int n = arr.size();

    for(int i = 0; i < k; i++)
        pq.push({arr[i], i});

    res.push_back(pq.top().first);

    for(int i = k; i < n; i++)
    {
        pq.push({arr[i], i});

        while(pq.top().second <= i-k)
            pq.pop();

        res.push_back(pq.top().first);
    }

    return res;
}

int main()
{
    vector<int> arr = {1,2,3,1,4,5,2,3,6};

    auto res = maxOfSubarrays(arr,3);

    for(auto x : res)
        cout << x << " ";
}