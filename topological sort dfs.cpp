// Topological sort
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

void solve(int node, vector<int> adj[], stack<int>& st, vector<bool>& visited)
    {
        visited[node] = true;
        
        for(auto itr: adj[node])
        {
            if(!visited[itr])
                solve(itr, adj, st, visited);
        }
        
        st.push(node);
    }
    
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        stack<int> st;
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                solve(i, adj, st, visited);
            }
        }
        
        vector<int> ans;
        while(!st.empty())
           {
               ans.push_back(st.top());
               st.pop();
           }
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}