// Number of pairs

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

int findParent(int node, vector<int>& parent)
        {
            if(node == parent[node])
                return node;
                
            return parent[node] = findParent(parent[node], parent);
        }
        
        void join(int u, int v, vector<int>& parent, vector<int>& rank)
        {
            u = findParent(u, parent);
            v = findParent(v, parent);
            
            if(u==v)
                return ;
                
            if(rank[u] < rank[v])
                parent[u] = v;
            else if(rank[u] > rank[v])
                parent[v] = u;
            else{
                parent[v] = u;
                rank[u]++;
            }
            return ;
        }
    
        long long int numberOfPairs(vector<vector<int>> &pairs,int p,int n)
        {
            vector<int> parent(n);
            vector<int> rank(n, 0);
            
            for(int i=0; i<n; i++)
                parent[i] = i;
            
            for(auto itr: pairs)
                join(itr[0], itr[1], parent, rank);
                
            unordered_map<int, long long int> mp;
            for(int i=0; i<n; i++)
                mp[findParent(i, parent)]++;
                
            long long int ans = 0;
            vector<long long int> count;
            
            for(auto itr: mp)
                count.push_back(itr.second);
                
            for(int i=1; i<count.size(); i++)
                count[i] += count[i-1];
                
            for(int i=count.size()-1; i>0; i--)
                ans += count[i-1]*(count[i]-count[i-1]);
            
            return ans;
        }