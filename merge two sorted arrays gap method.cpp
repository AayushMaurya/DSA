// Merge two sorted arraya
// Using gap method

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

void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int gap = ceil((float)(m+n)/2);
            while(gap>0)
            {
                int i=0, j=gap;
                while(j<m+n)
                {
                    if(j<n && arr1[i] > arr1[j])
                        swap(arr1[i], arr1[j]);
                    else if(j>=n && i<n && arr1[i] > arr2[j-n])
                        swap(arr1[i], arr2[j-n]);
                    else if(j>=n && i>=n && arr2[i-n] > arr2[j-n])
                        swap(arr2[i-n], arr2[j-n]);
                    i++;
                    j++;
                }
                if(gap==1)
                    gap=0;
                else gap=ceil((float)gap/2);
            }
        } 

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}