// Check if gaph is bipartite
// BFS

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

bool check(int node, vector<vector<int>>& graph, vector<int>& color)
    {
        queue<int> q;
        q.push(node);
        
        color[node] = 1;
        
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            
            for(auto itr: graph[temp])
            {
                if(color[itr]==-1)
                {
                    color[itr] = 1-color[temp];
                    q.push(itr);
                }
                else if(color[itr] == color[temp])
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        
        for(int i=0; i<V; i++)
        {
            if(color[i]==-1)
            {
                if(!check(i, graph, color))
                    return false;
            }
        }
        return true;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}