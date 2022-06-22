// Three sum closest

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

int threeSumClosest(vector<int> arr, int target) {
        
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int ans = INT_MAX;
        
        for(int i=0; i<n-2; i++)
        {
            int l = i+1, r=n-1;
            int sum;
            
            while(l<r)
            {
                sum = arr[i] + arr[l] + arr[r];
                if(sum==target)
                    return sum;
                    
                if(abs(ans-target) == abs(sum-target))
                    ans = max(ans, sum);
                else if(abs(ans-target) > abs(sum-target))
                    ans = sum;
                
                if(sum<target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }