// Fill the tank

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

    long long solve(int s, int p, unordered_map<int, vector<int>>& adj, int* cap)
    {
        long long ans=0;
        long long children = 0;
        
        for(auto itr: adj[s])
        {
            if(itr!=p)
            {
                children++;
                long long re = solve(itr, s, adj, cap);
                
                if(re>1e18 || re==-1){
                    return -1;
                }
                ans = max(ans, re);
            }
        }
        
        return cap[s-1] + (children*ans);
        
    }
    
    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap){
       
       unordered_map<int, vector<int>> adj;
       
       for(auto itr: Edges){
           adj[itr[0]].push_back(itr[1]);
           adj[itr[1]].push_back(itr[0]);
       }
           
        long long ans = solve(S, -1,  adj, Cap);
        
        if(ans == -1 || ans > 1e18)
            return -1;
        
        return ans;
       
    }