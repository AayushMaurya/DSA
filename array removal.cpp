// Array Removal

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

int removals(vector<int>& a, int k){
        
        sort(a.begin(), a.end());
        int ans=0, n=a.size();
        
        int i=0, j=0;
        while(j<n && a[j]-a[i] <= k)
            j++;
        
        ans = j-i;
        // cout<<ans<<endl;
        while(j<n)
        {
            while(j<n && a[j]-a[i]<=k)
                j++;
            ans = max(ans, j-i);
            i++;
            j++;
        }
        
        return n-ans;
    }