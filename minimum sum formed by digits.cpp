// minimum som formed by digits

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
# define pii pair<int, int>
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

long long int minSum(int arr[], int n)
    {
        sort(arr, arr+n);
        long long int a1=0, a2=0;
        
        for(int i=0; i<n; i++)
        {
            if(i%2==1)
                a1 = a1*10 + arr[i];
            else
                a2 = a2*10 + arr[i];
        }
        
        return a1+a2;
    }