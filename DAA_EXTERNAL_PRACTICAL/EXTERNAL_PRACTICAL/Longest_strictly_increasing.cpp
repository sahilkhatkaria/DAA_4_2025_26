#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    vector<int> tails;

    for (int num : nums)
    {
        auto it = lower_bound(tails.begin(), tails.end(), num);

        if (it == tails.end())
        {
            tails.push_back(num);
        }
        else
        {
            *it = num;
        }
    }

    return tails.size();
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums); // Output: 4
}
























// #include <bits/stdc++.h>
// using namespace std;

// int longest_strictly(vector<int> &arr)
// {
//     vector<priority_queue<int>> vpq;

//     for (int i = arr.size() -1; i < 0; i--)
//     {
//         if(vpq.empty())
//         {
//             vpq.push_back(arr[i])
//         }
//         else
//         {

//         }
//     }

// }

// int main()
// {

//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     return 0;
// }

//     for (int num : nums) {