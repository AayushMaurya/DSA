// Leaders in array

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

vector<int> leaders(int a[], int n){
        vector<int> ans;
        int maxi=a[n-1];
        for(int i=n-1; i>=0; i--)
        {
            maxi = max(maxi, a[i]);
            if(a[i] == maxi)
                ans.push_back(a[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}