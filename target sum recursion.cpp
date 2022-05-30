// Target sum
// Recursion

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

int helper(vector<int>& nums, int index, int sum, int target)
    {
        if(index<0)
        {
            if(sum==target)
                return 1;
            else
                return 0;
        }
        if(sum>target)
            return 0;
        
        return helper(nums, index-1, sum, target) + helper(nums, index-1, sum+nums[index], target);
    }
  
    int findTargetSumWays(vector<int>&A ,int target) {
        int sum=0;
        for(int i=0; i<A.size(); i++)
            sum+=A[i];
        
        if((sum+target)%2==1)
            return 0;
        
        sum = (sum+target)/2;
        
        return helper(A, A.size()-1, 0, sum);
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}