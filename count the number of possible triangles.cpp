// Count the number of possible triangles

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

int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr, arr+n);
        int ans=0;
        
        for(int i=n-1; i>0; i--)
        {
            int sum = arr[i];
            
            int l=0, r=i-1;
            while(l<r)
            {
                if(arr[l] + arr[r] > sum)
                {
                    ans += (r-l);
                    r--;
                }
                else
                    l++;
            }
        }
        
        return ans;
    }