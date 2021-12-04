// Find the triplet that sum equal to a given number
// using two sorting and two pointer technique

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


void solve()
{
	int n, sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0 ; i<n ; i++)    cin>>arr[i];

    for(int i=0 ; i<n ; i++)
    {
        int a=arr[i];
        int start=i+1, end=n-1;
        while(start<end)
        {
            if(arr[start]+arr[end] == sum-a)
                return true;
            else if(arr[start]+arr[end] < sum-a)
                start++;
            else
                end--;
        }
    }

    return false;
}

int main()
{
	solve();
	return 0;
}