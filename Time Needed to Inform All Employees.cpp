// Time Needed to Inform All Employees

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


    int dfs(int node, vector<int> adj[], vector<int>& informTime)
    {
        int ans=0;
        
        for(auto itr: adj[node])
        {
            ans = max(ans, dfs(itr, adj, informTime));
        }
        
        return ans + informTime[node];
    }
        
    
    
    int numOfMinutes(int n, int head, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> adj[n];
        for(int i=0; i<n; i++)
        {
            if(i == head)
                continue;
            adj[manager[i]].push_back(i);
        }
        
        int ans = 0;
        
        for(auto itr: adj[head])
            ans = max(dfs(itr, adj, informTime), ans);
        
        return informTime[head] + ans;
    }