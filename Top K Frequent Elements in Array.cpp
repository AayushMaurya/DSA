// Top K Frequent Elements in Array

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

vector<int> topK(vector<int>& nums, int k) {
        
        map<int, int> mp;
        for(auto itr: nums)
            mp[itr]++;
            
        priority_queue<pair<int, int>> pq;
        
        for(auto itr: mp)
            pq.push(make_pair(itr.second, itr.first));
        
        vector<int> ans;
        
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }