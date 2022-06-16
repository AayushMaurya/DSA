// pairs with specific difference

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

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int k)
    {
        int take[N];
        int escape[N];
        sort(arr, arr+N);
        take[0] = 0;
        escape[0] = 0;
        
        for(int i=1; i<N; i++)
        {
            if(arr[i]-arr[i-1] < k)
            {
                take[i] = escape[i-1] + arr[i] + arr[i-1];
                escape[i] = max(take[i-1], escape[i-1]);
            }
            else{
                take[i] = max(take[i-1], escape[i-1]);
                escape[i] = take[i];
            }
        }
        return max(take[N-1], escape[N-1]);
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}