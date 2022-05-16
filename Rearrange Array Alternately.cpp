// Rearrange Array Alternately
// Time Complexity: O(n)
// Space Complexity: O(1)

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

void rearrange(long long *arr, int n) 
    { 
        long long max = arr[n-1]+1;
        int s=0, e=n-1;
        for(int i=0; i<n; i++)
        {
            if(i%2==0)
                arr[i] = arr[i] + (arr[e--]%max)*max;
           else
                arr[i] = arr[i] + (arr[s++]%max)*max;
        }
        for(int i=0; i<n; i++)
            arr[i] = arr[i]/max;
    }


int main(){
    
solve();
    return 0;
}