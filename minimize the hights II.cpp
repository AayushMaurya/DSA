// Minimize the heights II

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

int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr+n);
        
        int ans = arr[n-1]-arr[0];
        int l=arr[n-1]-k;
        int s=arr[0]+k;
        
        for(int i=0;  i<n-1; i++)
        {
            int mx = max(l, arr[i]+k);
            int mn = min(s, arr[i+1]-k);
            
            if(mn<0)
                continue;
             ans = min(ans, mx-mn);
        }
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}