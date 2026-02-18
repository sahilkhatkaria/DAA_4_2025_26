// coco eating bananas : we are given h hours and n no of piles that has piles[i] bananas , we need to calculate the minimum no of banana she should eat so that she finishes all the bananas within h hours

#include <bits/stdc++.h>
using namespace std;

// brute force : find the value of k starting from max val in arr to 0 while h > 0

// int findminimumspeed(vector<int> &arr, int h)
// {
//     int n = arr.size();
//     if (h == n)
//     {
//         return *max_element(arr.begin(), arr.end());
//     }

//     int k = *max_element(arr.begin(), arr.end()); // O(n)

//     int val = k;

//     int minkreq = k;

//     while (val > 0)
//     {

//         int hour = h;
//         for (int i = 0; i < n; i++)
//         {
//             // for each pile check if it is eatable at k speed within hour
//             int temp = arr[i];
//             while (temp > 0)
//             {
//                 temp -= val;
//                 hour--;

//             }
//         }

//         if (hour >= 0)
//         {
//             minkreq = min(minkreq, val);
//         }

//         val--;
//     }

//     return minkreq;
// }



// int findminimumspeed(vector <int> &arr,int h)
// {
//     int k = *max_element(arr.begin(),arr.end());

//     int mink = k;

//     for (int i = k; i >=1; i--)
//     {
//         int hour = 0;
//         for(int x : arr)
//         {
//             hour += (x + i -1)/i;
//         }

//         if(hour<= h)
//         {
//             mink = min(mink,i);
//         }
//     }

//     return mink;
    
// }


int hoursreq(vector <int> &arr,int val)
{
    int hour = 0; // calculate required hour

    for(int x : arr)
    {
        hour += (x +val - 1)/val;
    }

    return hour;
     
}


int findminimumspeed(vector <int> &arr,int h)
{
    int k  = *max_element(arr.begin(),arr.end());

    int mink = k;

    int left = 0, right = k;

    while(left <= right)
    {
        int mid = left + (right-left)/2;

        if(hoursreq(arr,mid) <= h)
        {
            mink = mid;
            right = mid -1;
        }

        else
        {
            left = mid +1;
        }

    }

    return mink;
    
}

int main()
{

    vector<int> piles = {3, 6, 7, 11};

    int hour = 8;

    int res = findminimumspeed(piles, hour);  // k should be four

    cout << res << endl;

    return 0;
}