// Minimum cost path

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

int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        
        priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> q;
        
        q.push({0, {0, 0}});
        
        while(!q.empty())
        {
            int dis = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            
            dis += grid[x][y];
            
            if(x+1<n && distance[x+1][y] > dis){
                q.push({dis, {x+1, y}});
                distance[x+1][y] = dis;
            }
                
            if(y+1<n && distance[x][y+1] > dis){
                q.push({dis, {x, y+1}});
                distance[x][y+1] = dis;
            }
            
            if(x-1>=0 && distance[x-1][y] > dis){
                q.push({dis, {x-1, y}});
                distance[x-1][y] = dis;
            }
                
            if(y-1>=0 && distance[x][y-1] > dis){
                q.push({dis, {x, y-1}});
                distance[x][y-1] = dis;
            }
            
        }
        
        return distance[n-1][n-1] + grid[n-1][n-1];
    }