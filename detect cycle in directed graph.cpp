// Detect cycle in directed graph

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

bool check(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& dfs)
    {
        visited[node] = true;
        dfs[node] = true;
        
        for(auto itr: adj[node])
        {
            if(!visited[itr])
            {
                if(check(itr, adj, visited, dfs))
                    return true;
            }
            else if(dfs[itr])
                    return true;
        }
        dfs[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> dfs(V, false);
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                if(check(i, adj, visited, dfs))
                    return true;
            }
        }
        return false;
    }