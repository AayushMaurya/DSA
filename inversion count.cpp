// Inversion Count 
// using merge sort

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

long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right)
    {
        long long int inv_count=0;
        long long int i=left, j=mid, k=left;
        
        while((i<=mid-1) && (j<=right))
        {
            if(arr[i]<=arr[j])
                temp[k++] = arr[i++];
            else{
                temp[k++] = arr[j++];
                inv_count += mid-i;
            }
        }
        
        while(i<=mid-1)
        {
            temp[k++] = arr[i++];
        }
        
        while(j<=right)
        {
            temp[k++] = arr[j++];
        }
        
        for(i=left; i<=right; i++)
            arr[i] = temp[i];
            
        return inv_count;
    }
    
    long long int merge_Sort(long long arr[], long long temp[], long long left, long long right)
    {
        long long mid;
        long long int inv_count=0;
        
        if(right>left)
        {
            mid = (left+right)/2;
            inv_count+=merge_Sort(arr, temp, left, mid);
            inv_count+=merge_Sort(arr, temp, mid+1, right);
            
            inv_count+=merge(arr, temp, left, mid+1, right);
            
        }
        return inv_count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        return merge_Sort(arr, temp, 0, N-1);
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}