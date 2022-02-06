// Find nth root of m

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

int power(int mid, int n, int m)
{
    unsigned long long int res=1;
    for(int i=0; i<n; i++)
    {
        res=res*mid;
        if(res>m)
            return m+1;
    }
    return (int)res;
}

int solve()
{
    int n, m;
    cin>>n>>m;

    if(m==1 || n==1)
        return m;

    int low=1, high=m;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int temp=power(mid, n, m);
        if(temp==m)
            return mid;
        else if(temp<m)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

int main(){
    cout<<solve()<<endl;
    return 0;
}