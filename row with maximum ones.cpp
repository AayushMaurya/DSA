// Rows with maximum ones

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

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        int i=0, j=m-1;
        
        int ans=-1;
        
        while(i<n && j>=0)
        {
            if(arr[i][j] == 1)
            {
                ans = i;
                j--;
            }
            else
                i++;
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