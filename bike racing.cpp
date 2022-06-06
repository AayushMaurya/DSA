// Bike Racing

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

long buzzTime(long N, long M, long L, long H[], long A[])
    {
        long left=0, right=max(L, M);
        long ans=-1;
        while(left<=right)
        {
            long mid=(left+right)/2;
            long sum=0;
            for(long i=0; i<N; i++)
            {
                long temp = H[i] + mid*A[i];
                if(temp>=L)
                    sum+=temp;
            }
            if(sum==M)
                return mid;
            else if(sum>M){
                ans=mid;
                right = mid-1;
            }
            else
                left=mid+1;
        }
        return ans;;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}