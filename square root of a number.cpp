// Square root of a number

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
ll max(ll x, ll y)
{
    return (x>y)?x:y;
}
ll min(ll x, ll y)
{
    return (x>y)?y:x;
}
void swap(ll *x, ll *y)
{
    ll temp = *x;
    *x = *y;
    *y = temp;
}

long long int floorSqrt(long long int x) 
{
    long long int st=1;
    long long int en=x;
    
    while(st<=en)
    {
        long long int mid = (st+en)/2;
        
        if(mid*mid == x)
            return mid;
        else if(mid*mid > x)
            en = mid-1;
        else
            st = mid+1;
    }
    return en;
}