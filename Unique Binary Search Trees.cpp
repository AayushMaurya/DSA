// number of Unique Binary Search Trees 

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


int numTrees(int n) {
        int dp[n+1];
        dp[0]=1;
        for(int i=1; i<=n; i++)
        {
            dp[i]=0;
            for(int j=0; j<i; j++)
                dp[i]+=dp[j]*dp[i-j-1];
        }
        return dp[n];
    }

int main(){
    
    solve();
    return 0;
}