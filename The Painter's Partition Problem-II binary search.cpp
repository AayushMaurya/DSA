// The Painter's Partition Problem-II
// binary search

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

bool check(int arr[], int n, long long mid, int k)
    {
        long long sum = 0, ans=1;
        
        for(int i=0; i<n; i++)
        {
            if(sum + arr[i] > mid)
            {
                ans++;
                if(ans > k || arr[i]>mid)
                    return false;
                sum = arr[i];
            }
            else{
                sum += arr[i];
            }
        }
        return true;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        long long high = 0;
        long long low = arr[0];
        
        for(int i=0; i<n; i++)
        {
            high += arr[i];
            low = max(low, 1LL*arr[i]);
        }
        long long ans=high;
        while(low<=high)
        {
            long long mid = (low+high)/2;
            
            if(check(arr, n, mid, k))
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        
        return ans;
        
    }