// Search in a row-column sorted Matrix

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

bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        int i=0, j=m-1;
        while(i<n && j>=0)
        {
            if(matrix[i][j] == x)
                return true;
            else if(matrix[i][j] > x)
                j--;
            else 
                i++;
        }
        return false;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}