// Djkistra algorithm

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

vector<int> djkistra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>> pq;
    pq.push_back({0, S});
    dist[S] = 0;
    while(!pq.empty())
    {
        pair<int, int> p=pq.top();
        pq.pop();
        int a=p.second;
        for(int i=0; i<adj[a].size(); i++)
        {
            int res=adj[a][i][0];
            int w = adj[a][i][1];
            if(w+dist[a] < dist[res])
            {
                dist[res] = w+dist[a];
                pq.push_back({-1*dist[res], res});
            }
        }
    }
    return dist;
}

int main()
{
    int V, E;
    cin>>V>>E;
    vector<vector<int, int>> adj[V];
    int i=0;
    while(i++<E)
    {
        int u, v, w;
        cin>>u>>v>>w;
        vector<int> t1, t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }
    int S;
    cin>>S;

    vector<int> res=djkistra(A, adj, S);
    for(int i=0; i<V; i++)
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;

}