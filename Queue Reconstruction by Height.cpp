// Queue Reconstruction by Height
// Topological sorting

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

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        int n = people.size();
        
        sort(people.begin(), people.end());
        
        vector<int> cardinality(n);
        vector<bool> vis(n, false);
        
        for(int i=0; i<n; i++)
        {
            cardinality[i] = people[i][1];
        }
        
        priority_queue<int, vector<int>, greater<int>> q;
        
        for(int i=0; i<n; i++)
        {
            if(cardinality[i]==0)
                q.push(i);
            
        }
        
        vector<vector<int>> ans;
        
        while(!q.empty())
        {
            int node = q.top();
            q.pop();
            vis[node] = true;
            
            ans.push_back({people[node][0], people[node][1]});
            
            for(int i=0; i<n; i++)
            {
                if(!vis[i] && people[i][0] <= people[node][0])
                {
                    cardinality[i]--;
                    
                    if(cardinality[i]==0)
                        q.push(i);
                    
                }
            }
        }
        
        return ans;
    }