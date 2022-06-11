// Minimum operations to reduce X to zero

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

int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for(auto itr: nums)
            total += itr;
        int sum = total-x;
        if(sum<0)
            return -1;
        if(sum==0)
            return nums.size();
        
        int i=0, j=0;
        int ans=-1;
        total = 0;
        while(j<nums.size())
        {
            // cout<<total<<endl;
            if(total < sum)
            {
                total += nums[j];
                j++;
            }
            else if(total > sum)
            {
                total -= nums[i];
                i++;
            }
            else
            {
                ans = max(ans, j-i);
                total += nums[j];
                total -= nums[i];
                i++;
                j++;
            }
        }

        while(total > sum && i<nums.size())
        {
            total -= nums[i];
            i++;
        }
        if(total == sum)
            ans = max(ans, j-i);
        
        if(ans == -1)
            return -1;
        return nums.size() - ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}