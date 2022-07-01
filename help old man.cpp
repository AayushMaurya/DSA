// Help Old Man

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

void solve(int src, int helper, int dest, vector<pair<int, int>>& ans, int n)
    {
        if(n==1){
            ans.push_back({src, dest});
            return;
        }
        
        solve(src, dest, helper, ans, n-1);
        
        ans.push_back({src, dest});
        
        solve(helper, src, dest, ans, n-1);
    }
    
    vector<int> shiftPile(int N, int n){
        pvt=n;
        
        vector<int> ans;
        vector<pair<int, int>> res;
        
        solve(1, 2, 3, res, N);
        
        ans.push_back(res[n-1].first);
        ans.push_back(res[n-1].second);
        
        return ans;
    }