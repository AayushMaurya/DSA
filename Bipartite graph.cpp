// Bipartite graph 

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


bool solve(int node, vector<int> adj[], vector<int>& visited)
{
    for(auto itr: adj[node])
    {
        if(visited[itr] == -1)
        {
            visited[itr] = 1-visited[node];
            if(!solve(itr, adj, visited))
                return false;
        }
        else if(visited[itr] == visited[node])
            return false;
    }

    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> visited(V, -1);

    for(int i=0; i<V; i++)
    {
        if(visited[i] == -1)
        {
            visited[i] = 1;
            if(!solve(i, adj, visited));
                return false;
        }
    }

    return true;
}

