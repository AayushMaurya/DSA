// median of 2 sorted array of equal size
// O(n)

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
    int n;
    cin>>n;
    int arr1[n], arr2[n];

    for(int i=0 ; i<n ; i++)
        cin>>arr1[i];

    for(int i=0 ; i<n ; i++)
        cin>>arr2[i];

    int i=0, j=0, count=0, res=0;
    while(i<n && j<n)
    {  
        count++;
        if(arr1[i]<arr2[j]){
            if(count==n || count==n+1)
                res+=arr1[i];
            i++;
        }
        else {
            if(count==n || count==n+1)
                res+=arr2[j];
            j++;
        }
    }
    while(j<n)
    {
        count++;
        if(count==n || count==n+1)
            res+=arr2[j];
        j++;
    }
    while(i<n)
    {
        count++;
        if(count==n || count==n+1)
            res+=arr1[i];
        i++;
    }
    cout<<res/2<<endl;;
    return;
}

int main()
{
	solve();
	return 0;
}