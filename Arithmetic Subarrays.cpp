// Arithmetic Subarrays

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

bool solve(vector<int>& nums, int l, int r)
    {
        int n = r-l+1;
        vector<bool> pres(n, false);
        int a = nums[l];
        int b = nums[r];
        for(int i=l; i<=r; i++)
        {
            a = min(nums[i], a);
            b = max(nums[i], b);
        }
        
        if((b-a)%(n-1)!=0)
            return false;
        
        int d = (b-a)/(n-1);
        if(d==0)
            return true;
        
        for(int i=l; i<=r; i++)
        {
            if((nums[i]-a)%d!=0)
                return false;
            
            int index = (nums[i]-a)/d;
            if(pres[index])
                return false;
            pres[index] = true;
        }
    
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> ans;
        
        for(int i=0; i<l.size(); i++)
        {
            ans.push_back(solve(nums, l[i], r[i]));
        }
        return ans;
    }