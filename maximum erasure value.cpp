// Maximum ersure value

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

int maximumUniqueSubarray(vector<int>& nums) {
        int i=0, j=0;
        
        int ans=0;
        int curr=0;
        map<int, int> mp;
        while(j<nums.size())
        {
            if(mp[nums[j]])
            {
                ans = max(ans, curr);
                while(nums[i]!=nums[j])
                {
                    curr -= nums[i];
                    mp[nums[i]]--;
                    i++;
                }
                i++;
                j++;
            }
            else{
                curr+=nums[j];
                mp[nums[j]]++;
                j++;
            }
        }
        ans = max(curr, ans);
     return ans;   
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}