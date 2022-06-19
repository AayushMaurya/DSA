// Palindromic partitioning


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

bool isPlaindrome(string str, int i, int j)
{
    while(i<j)
    {
         if( str[i] != str[j]) return false;
         i++;
         j--;
    }
    return true;
}
int solve(string &str, int i, int j, vector<vector<int>>& dp)
{
    if( i>= j) return 0;
    
     if( dp[i][j] != -1) return dp[i][j];
    
    if( isPlaindrome(str,i,j)) return 0;
    
   
    int ans= INT_MAX;
    
    for(int k = i;k<=j-1;k++)
    {
         int left = solve(str, i, k, dp);
         int right = solve(str,k+1,j, dp);
         
         ans= min(left + right + 1,ans);
    }
    return dp[i][j] = ans;
}
   int palindromicPartition(string str)
   {
       int n = str.size();
       vector<vector<int>> dp(n, vector<int>(n, -1));
       return solve( str ,0,n-1, dp);
   }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}