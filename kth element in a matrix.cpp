// Kth element in a matrix

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
# define pii pair<int, int>
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

int kthSmallest(int mat[][], int n, int k)
{
    int l=0, r=mat[n-1][n-1];
    while(l<=r)
    {
        int m = l + (r-l)/2;
        int count=0;

        for(int i=0; i<n; i++)
        {
            int left = 0, right = n-1;
            while(left <= right)
            {
                int mid = left + (right-left)/2;
                if(mat[i][mid] <= m)
                    left = mid + 1;
                else
                    right = mid-1;
            }
            count += left;
        }
        if(count < k)
            l = m+1;
        else
            r = m-1;
    }
    return l;
}