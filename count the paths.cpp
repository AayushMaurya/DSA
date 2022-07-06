// Count the paths

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

int dfs(vector<int> adj[], int source, int destination, vector<int>& dp)
    {
        if(source == destination)
        {
            return 1;
        }
        
        if(dp[source]!=-1)
            return dp[source];
        
        int ans=0;
        
        for(auto itr: adj[source]){
            
            ans += dfs(adj, itr, destination, dp);
        }
            
        return dp[source] = ans;
    }
    

    int possible_paths(vector<vector<int>>edges, int n, int s, int d){
        
        vector<int> adj[n];
        
        if(s==d)
            return 1;
            
        vector<int> dp(n, -1);
        
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<bool> vis(n, false);
        
        int ans=0;
        
        for(auto itr: adj[s])
            ans += dfs(adj, itr, d, dp);
            
       return ans;
        
    }