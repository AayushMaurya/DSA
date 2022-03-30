// Minimum Number of jumps

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

int solve(int arr[], int n)
{
    if(arr[0]==0 && n==1)   return 0;
    if(arr[0]==0)   return -1;

    int jumps=0, far=0, end=0;
    for(int i=0; i<n-1; i++)
    {
        far = max(far, i+arr[i]);
        if(i==end)
        {
            if(i==far)
                return -1;
            jumps++;
            end = far;
        }
    }
    return jumps;
}


int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<solve(arr, n)<<endl;
    return 0;
}