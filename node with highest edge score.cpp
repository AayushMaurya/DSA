// node with highest edge score

include<bits/stdc++.h>
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

// **********************************

int edgeScore(vector<int>& edges) {
        unordered_map<int, long long int> mp;
        int n = edges.size();
        
        for(int i=0; i<n; i++)
        {
            mp[edges[i]] += i;
        }
        int ans = 0, sum = 0;
        for(auto m: mp)
        {
            if(m.second > sum)
            {
                sum = m.second;
                ans = m.first;
            }
            else if(m.second == sum)
            {
                ans = min(ans, m.first);
            }
        }
        
        return ans;
    }