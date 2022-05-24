// Longest increasing subsequence

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


int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<n; i++)
        {
            if(nums[i]>ans.back())
                ans.push_back(nums[i]);
            else{
                auto index = lower_bound(ans.begin(), ans.end(), nums[i]);
                *index = nums[i];
            }
        }
        return ans.size();
    }

int main(){
    
    int n;
    cin>>n;
vector<vector<int>> vec(n, vector<int>(n));
for(int i=0; i<n; i++)
    cin>>vec[i][0]>>vec[i][1];

cout<<solve(vec, n, n)<<endl;
    return 0;
}