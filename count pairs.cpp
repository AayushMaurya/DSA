// Count number of pairs where X^y > Y^x

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

int upper_bound(int arr[], int n, int ele)
    {
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(arr[mid] > ele)
            {
                ans=mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
    
    long long countPairs(int X[], int Y[], int M, int N)
    {
        int zeros=0, one=0, two=0, three=0, four=0;
        sort(Y, Y+N);
        for(int i=0; i<N; i++)
        {
            if(Y[i]==0) zeros++;
            if(Y[i]==1) one++;
            if(Y[i]==2) two++;
            if(Y[i]==3) three++;
            if(Y[i]==4) four++;
        }
        
        long long ans=0;
        
        for(int i=0; i<M; i++)
        {
            if(X[i]==0)
                continue;
            else if(X[i] == 1)
            {
                ans += zeros;
            }
            else if(X[i]==2)
            {
                int index = upper_bound(Y, N, 2);
                if(index!=-1)
                {
                    ans+=N-index;
                }
                ans -= three;
                ans -= four;
                ans += one;
                ans += zeros;
            }
            else{
                int index = upper_bound(Y, N, X[i]);
                
                if(index!=-1)
                    ans += N-index;
                ans += one + zeros;
                if(X[i] == 3)
                    ans += two;
            }
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