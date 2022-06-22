// quick select algorithm
// find the kth largest number

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

int quickselect(vector<int>& nums, int low, int high)
    {
        int i=low+1, j=high;
        while(i<=j)
        {
            while(i<=high && nums[i] >= nums[low])  i++;
            
            while(j>=0 && nums[j] < nums[low])  j--;
            
            if(i<j) swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }
        
    
    int findKthLargest(vector<int>& nums, int k) {
        
        int l=0, r=nums.size()-1;
        
        // k = nums.size()-k;
        
        while(l<=r)
        {
            int mid = quickselect(nums, l, r);
            
            if(mid == k-1)
                return nums[mid];
            else if(mid<k-1)
                l=mid+1;
            else
                r=mid-1;
        }
        return 1;
    }