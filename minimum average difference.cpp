// Minimum average difference

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

int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long int sum = 0;
        for(auto itr: nums)
            sum+=itr;
        
        int mn=INT_MAX;
        long long int sum1=0, sum2=sum;
        int ans=0;
        for(int i=0; i<n; i++)
        {
            sum1+=nums[i];
            sum2-=nums[i];
            int x = n-i-1;
            if(i==n-1)
                x=1;
            int temp = abs((sum1/(i+1)) - (sum2/(x)));
            if(temp < mn){
                ans=i;
                mn=temp;
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