// Top K frequent elements
// Bucket Sort

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

vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        
        for(auto itr: nums)
            mp[itr]++;
        
        vector<vector<int>> res(nums.size()+1);
        
        for(auto m: mp)
        {
            res[m.second].push_back(m.first);
        }
        
        vector<int> ans;
        
        for(int i=res.size()-1; i>=0; i--)
        {
            for(int j=0; j<res[i].size(); j++)
            {
                ans.push_back(res[i][j]);
                if(ans.size()==k)
                    return ans;
            }
        }
        
        return ans;
    }