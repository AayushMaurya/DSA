// Sqrt(x)

#include <bits/stdc++.h>
using namespace std;


int mySqrt(int x) {
        int left = 0, right = x, ans;
        
        while(left <= right)
        {
            int mid = (left + right)/2;
            
            if(1LL*mid*mid == x)
                return mid;
            else if(1LL*mid*mid > x)
                right = mid-1;
            else{
                left = mid+1;
                ans = mid;
            }
        }
        
        return ans;
    }