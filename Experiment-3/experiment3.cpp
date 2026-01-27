#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<char> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    unordered_map<int,int> mp;

    int sum = 0;
    int maxi = 0;

    mp[0] = -1;   

    for(int i = 0; i < n; i++)
    {
        if(v[i] == 'P')
            sum += 1;
        else
            sum -= 1;

        if(mp.find(sum) != mp.end())
        {
            int len = i - mp[sum];
            if(len > maxi)
                maxi = len;
        }
        else
        {
            mp[sum] = i;  
        }
    }

    cout << maxi;
}
