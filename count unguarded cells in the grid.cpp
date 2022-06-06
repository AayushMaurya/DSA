// count unguarded cells in the grid

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

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        set<pair<int, int>> g, w;
        int guarded=0;
        
        for(auto itr: walls)
            w.insert({itr[0], itr[1]});
        
        for(auto itr: guards)
            g.insert({itr[0], itr[1]});
        
        for(auto x: guards)
        {
            int l = x[1]-1;
            int r = x[1]+1;
            int u = x[0]-1;
            int d = x[0]+1;
            
            while(l>=0)
            {
                if(w.find({x[0], l})==w.end() && g.find({x[0], l})==g.end()){
                    if(!visited[x[0]][l]){
                        guarded++;
                        visited[x[0]][l] = true;
                    }
                    l--;
                }
                else    break;
            }
            
            while(r<n)
            {
                if(w.find({x[0], r})==w.end() && g.find({x[0], r})==g.end())
                {
                    if(!visited[x[0]][r])
                    {
                        guarded++;
                        visited[x[0]][r] = true;
                    }
                    r++;
                }
                else    break;
            }
            
            while(u>=0)
            {
                if(w.find({u, x[1]})==w.end() && g.find({u, x[1]})==g.end())
                {
                    if(!visited[u][x[1]])
                    {
                        guarded++;
                        visited[u][x[1]] = true;
                    }
                    u--;
                }
                else    break;
            }
            
            while(d<m)
            {
                if(w.find({d, x[1]})==w.end() && g.find({d, x[1]})==g.end())
                {
                    if(!visited[d][x[1]])
                    {
                        guarded++;
                        visited[d][x[1]]=true;
                    }
                    d++;
                }
                else break;
            }
            
        }
        return m*n - (g.size() + w.size() + guarded);
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}