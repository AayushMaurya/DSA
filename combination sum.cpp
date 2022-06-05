//  Combination Sum
// print all the combinations of element from an array to sum up to target

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

void solve(int index, vector<int>& nums, vector<vector<int>>& ans, vector<int>& res, int target)
    {
        
        if(index<0 || target<0)
            return ;
        
        if(target==0){
            ans.push_back(res);
            return ;
        }
        
        // take
        res.push_back(nums[index]);
        solve(index, nums, ans, res, target-nums[index]);
        res.pop_back();
    
        
        // escape
        solve(index-1, nums, ans, res, target);
            
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        
        solve(candidates.size()-1, candidates, ans, res, target);
        
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}