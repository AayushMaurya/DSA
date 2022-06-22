// Furthest Building You Can Reach

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

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue <int, vector<int>, greater<int> > pq;
        int n = heights.size();
        
        for(int i=0; i<n-1; i++)
        {
            int diff = heights[i+1] - heights[i];
            if(diff<=0)
                continue;
            pq.push(diff);
            if(pq.size()>ladders)
            {
                bricks -= pq.top();
                pq.pop();
            }
            if(bricks<0)    return  i;
        }
        return n-1;
    }