// Detect cycle in undirected graph
// DFS

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

bool helper(int src,vector<bool> &vis,vector<int> adj[],int parent){
        vis[src] = true;
        for(auto x : adj[src]){
            if(!vis[x]){
                if(helper(x,vis,adj,src)) return true;
            }
            else if(x != parent) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(helper(i,vis,adj,-1)){
                    return true;
                }
            }
        }
        return false;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}