// Rotten oranges

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

int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2)
                    q.push({i, j});
            }
        }
        
        int ans=0;
        
        while(!q.empty())
        {
            int t = q.size();
            
            for(int i=0; i<t; i++)
            {
                pair<int, int> temp = q.front();
                q.pop();
                
                int x = temp.first;
                int y = temp.second;
                // cout<<x<<" "<<y<<" ";
                
                if(x+1<m && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    q.push({x+1, y});
                }
                if(x-1>=0 && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    q.push({x-1, y});
                }
                if(y+1<n && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    q.push({x, y+1});
                    // cout<<"#"<<q.back().first<<" "<<q.back().second<<" ";
                }
                if(y-1>=0 && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    q.push({x, y-1});
                }
            }
            
            if(!q.empty())
                ans++;
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
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