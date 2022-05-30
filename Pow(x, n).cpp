// Pow(x, n)

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

double myPow(double x, int n) {
        double ans=1;
        long long int nn=n;
        if(nn<0)    nn=nn*-1;
        while(nn)
        {
            if(nn%2==1){
                ans=ans*x;
                nn--;
            }
            else
            {
                x=x*x;
                nn=nn/2;
            }
        }
        if(n<0) return (double)(1.0)/(double)(ans);
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}