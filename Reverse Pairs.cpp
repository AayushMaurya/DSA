// Reverse Pairs

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

int merge(vector<int>& nums, int start, int mid, int end)
    {
        int ans=0;
        int j=mid+1;
        
        for(int i=start; i<=mid; i++)
        {
            while(j<=end && nums[i] > 2LL*nums[j])
                j++;
            ans += j - (mid+1);
        }
        
        vector<int> temp;
        
        int left=start, right=mid+1;
        
        while(left<=mid && right<=end)
        {
            if(nums[left] < nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }
        
        while(left<=mid)
            temp.push_back(nums[left++]);
        while(right<=end)
            temp.push_back(nums[right++]);
        
        for(int i=start; i<=end; i++)
            nums[i] = temp[i-start];
        
        return ans;
    }
    
    int mergesort(vector<int>& nums, int start, int end)
    {
        if(start>=end)  return 0;
        
        int mid = (start+end)/2;
        
        int ans=mergesort(nums, start, mid);
        ans += mergesort(nums, mid+1, end);
        
        ans += merge(nums, start, mid, end);
        
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size()-1);
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}