// Integer Break

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

int helper(int n, vector<int>& dp)
    {
        if(dp[n]!=-1)
            return dp[n];
        
        int ans=INT_MIN;
        for(int i=1; i<n; i++){
            ans=max(ans, i*helper(n-i, dp));
            ans=max(ans, i*(n-i));
        }
        dp[n]=ans;
        cout<<n<<" = " <<ans<<endl;
        return ans;
    }
    
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        dp[1]=1;
        dp[2]=1;
        return helper(n, dp);
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}