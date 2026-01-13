#include <bits/stdc++.h>
using namespace std;

long long opc = 0;

void complexRec(int n) {

    opc ++;

   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {   // p == n, log(n) times 
       vector<int> temp(n);  // 
       opc ++;
       for (int i = 0; i < n; i++) {   // N TIMES
           temp[i] = i ^ p;
           opc ++;
       }
       p >>= 1;  // p becomes half
       opc ++;
   }

    //  n log(n) 

    opc+= n;

   vector<int> small(n);
   for (int i = 0; i < n; i++) {  // n times
       small[i] = i * i;
        opc ++;
    }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
       opc ++;
   } else {
       reverse(small.begin(), small.end());    // o (n/2)
        opc ++;
    }


   complexRec(n / 2);   // t(n/2)
   complexRec(n / 2);   // t(n/2)
   complexRec(n / 2);   // t(n/2)    --> total 3 t(n/2)
}


int main()
{

    // de comment to run

    // complexRec(10);
    // cout<<opc;   // --> total operations

    return 0;

}


// recurrence relation for the following fn :

/*

T(n) =   3T(n/2) + nlog(n) + n + n/2

in comparison to n log(n), 3n/2 is small 
so 3n/2 can be neglected
hence,


T(n) =   3T(n/2) + nlog(n)



complexity : O(n ^log(3))


operations will be counted with long long opc


depth will be  

n/2^k = 1

hence 

k (depth) = log(n)


*/