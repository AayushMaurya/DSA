// Bidirectional graph

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
// ll max(ll x, ll y)
// {
//     return (x>y)?x:y;
// }
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

void dfs(int u, unordered_map<int, vector<int>> &m, vector<bool> &visited)
    {
        visited[u] = true;
        for(auto v:m[u])
        {
            if(!visited[v])
                dfs(v, m, visited);
        }
    }
  
    int biGraph(int arr[], int n, int e) {
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<2*e; i+=2)
        {
            mp[arr[i]].push_back(arr[i+1]);
            mp[arr[i+1]].push_back(arr[i]);
        }
        
        for(int i=0; i<n; i++)
        {
            vector<bool> visited(n, false);
            visited[i]=true;
            dfs((i+1)%n, mp, visited);
            for(auto i:visited)
                if(!i)  return 0;
        }
        return 1;
    }

int main(){
    solve();
    return 0;
}