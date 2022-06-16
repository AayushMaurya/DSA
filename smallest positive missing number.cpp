// Smallest positive missing number

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

int missingNumber(int arr[], int n) 
    { 
        vector<bool> visited(n+1, false);
        
        for(int i=0; i<n; i++)
        {
            if(arr[i]>=0 && arr[i]<=n)
                visited[arr[i]] = true;
        }
        
        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
                return i;
        }
        return n+1;
    } 

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}