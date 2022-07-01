//  Minimum Moves to Equal Array Elements II

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

int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int mid = n/2;
        
        int ans=0;
        
        for(int i=0; i<n; i++)
            ans += abs(nums[i]-nums[mid]);
        
        return ans;
        
    }