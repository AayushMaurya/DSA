// Minimum platform problem

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

int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        int ans=0;
        int ma=0;
        int i=0, j=0;
        while(i<n && j<n)
        {
            if(arr[i]<=dep[j]){
                ma++;
                i++;
            }
           else{
               ma--;
                j++;
           }
           ans = max(ma, ans);
        }
        return ans;
    }