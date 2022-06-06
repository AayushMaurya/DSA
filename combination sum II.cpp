// Combination sum II

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

void solve(int index, int target, vector<int>& nums, vector<vector<int>>& ans, vector<int>& res)
    {
        if(target==0)
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=index; i<nums.size(); i++)
        {
            if(i!=index && nums[i]==nums[i-1])  continue;
            if(nums[i]>target)  break;
            res.push_back(nums[i]);
            solve(i+1, target-nums[i], nums, ans, res);
            res.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, ans, res);
 
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}