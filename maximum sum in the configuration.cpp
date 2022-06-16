// Maximum sum in the configuration

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

int max_sum(int A[],int N)
{
    int sum=0, ans=0;
    
    for(int i=1; i<N; i++)
    {
        sum += A[i];
        ans += A[i]*i;
    }
    int temp=ans;
    for(int i=0; i<N-1; i++)
    {
        temp = temp - sum + (N-1)*A[i];
        ans = max(ans, temp);
        sum += A[i] - A[i+1];
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