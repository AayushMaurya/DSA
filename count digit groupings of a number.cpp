// count digits grouping of a number

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

int solve(int index, string str, int sum, vector<vector<int>>& dp)
    {
        if(index == str.size())
            return 1;
        
        if(dp[index][sum] != -1)
            return dp[index][sum];
        
        int ans=0;
        int currsum = 0;
        
        for(int i=index; i<str.size(); i++)
        {
            currsum += str[i] - '0';
            if(currsum >= sum)
                ans += solve(i+1, str, currsum, dp);
        }
        dp[index][sum] = ans;
        return ans;
    }
    
    int TotalCount(string str){
        int n = str.size();
        
        vector<vector<int>> dp(str.size(), vector<int>(910, -1));
        
        int ans = solve(0, str, 0, dp);
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}