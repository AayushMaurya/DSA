// Raju and coins

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

int solve(int n, int k, int a[]){
        sort(a, a+n);
        int res=0;
        int sum=0;
        int j=0;
        for(int i=1; i<1000000000; i++)
        {
            if(i==a[j]){
                j++;
                continue;
            }
            else
            {
                sum+=i;
                res++;
            }
            if(sum>=k)
                break;
        }
        return res-1;
    }


int main(){
    int n, k;
    cin>>n>>k;

    int a[n];

    for(int i=0; i<n; i++)
        cin>>a[i];

    cout<<solve(n, k, a)<<endl;
    return 0;
}