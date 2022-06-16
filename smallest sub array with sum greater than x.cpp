// smallest subarray with sum greater than x

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

int smallestSubWithSum(int arr[], int n, int x)
    {
        int ans=INT_MAX, sum=0;
        int i=0, j=0;
        while(j<n)
        {
            if(sum<=x)
            {
                sum+=arr[j];
                j++;
            }
            else{
                ans = min(ans, j-i);
                sum -= arr[i];
                i++;
            }
        }
        while(sum > x)
        {
            ans = min(ans, j-i);
            sum -= arr[i];
            i++;
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