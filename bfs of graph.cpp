// BFS of graph

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

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    
        vector<bool> visited(V, false);
        vector<int> ans;
        
        // for(int i=0; i<V; i++)
        // {
        //     if(visited[i])  continue;
            queue<int> q;
            q.push(0);
            visited[0] = true;
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                
                ans.push_back(temp);
                
                for(auto itr: adj[temp])
                {
                    if(!visited[itr])
                    {
                        q.push(itr);
                        visited[itr] = true;
                    }
                }
                
            }
        // }
        return ans

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}