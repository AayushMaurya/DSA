// Longest consecutive sequence

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

int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        unordered_map<int, int> mp;
        int ans=1;
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        for(int i=0; i<n; i++)
        {
            if(!mp[nums[i]-1])
            {
                int j=nums[i];
                while(mp[j+1])  j++;
                
                ans=max(ans, j-nums[i]+1);
            }
        }
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}