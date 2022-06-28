// Minimum spanning tree
// Prims algorithm

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

int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);
        
        key[0]=0;
        parent[0] = -1;
        
        for(int count=0; count<V; count++)
        {
            int mi = INT_MAX;
            int u;
            
            for(int i=0; i<V; i++)
            {
                if(mst[i] == false && key[i] < mi){
                    u = i;
                    mi = key[i];
                }
            }
            mst[u] = true;
            // cout<<u<<" ";
            
            for(auto itr: adj[u])
            {
                int weight = itr[1];
                int v = itr[0];
                
                if(mst[v] == false && weight < key[v])
                {
                    parent[v] = u;
                    key[v] = weight;
                }
            }
            
        }
        
        int ans=0;
        
        for(int i=0; i<V; i++)
        {
            ans += key[i];
        }
        
        
        return ans;
    }