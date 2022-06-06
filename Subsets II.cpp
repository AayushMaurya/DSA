// Subsets II

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

void solve(int index, int n, vector<int>& nums, set<vector<int>>& ans, vector<int>& res)
    {
        if(index == n)
        {
            // sort(res.begin(), res.end());
            ans.insert(res);
            return;
        }
        
        // take
        res.push_back(nums[index]);
        solve(index+1, n, nums, ans, res);
        res.pop_back();
        
        // escape
        solve(index+1, n, nums, ans, res);
        
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> res;
        sort(nums.begin(), nums.end());
        solve(0, nums.size(), nums, st, res);
        
        vector<vector<int>> ans;
        for(auto itr: st)
            ans.push_back(itr);
        
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}