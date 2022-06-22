// Topological sort using khadens algorithm

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

vector<int> toposort(vector<int>& adj[], int V)
{
    vector<int> indegree(V, 0);

    for(int i=0; i<V; i++)
    {
        for(auto itr: adj[i])
            indegree[itr]++;
    }


    vector<int> ans;
    queue<int> q;

    for(int i=0; i<V; i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto itr: adj[node])
        {
            indegree[itr]--;
            if(indegree[itr] == 0)
                q.push(itr);
        }
    }
    return ans;
}