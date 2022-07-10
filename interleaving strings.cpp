// interleaving strings

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

int solve(string& s1, int i, string& s2, int j, string& s3, int k, vector<vector<int>>& dp)
    {
        if(i==s1.size() && j==s2.size() && k==s3.size())
            return true;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(i<s1.size())
        {
            if(s1[i] == s3[k])
            {
                if(solve(s1, i+1, s2, j, s3, k+1, dp)==1)
                    return 1;
            }
        }
        if(j<s2.size())
        {
            if(s2[j] == s3[k])
            {
                if(solve(s1, i, s2, j+1, s3, k+1, dp)==1)
                    return 1;
            }
        }
        dp[i][j] = 0;
        return 0;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        if(s1=="")
            return s2==s3;
        if(s2=="")
            return s1==s3;
        
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        
        if(solve(s1, 0, s2, 0, s3, 0, dp)==1)
            return true;
        
        return false;
    }