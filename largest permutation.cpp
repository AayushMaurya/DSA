// Largest Permutation

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

void KswapPermutation(int arr[], int n, int k)
    {
        int pos[n+1];
        for(int i=0; i<n; i++)
            pos[arr[i]] = i;
            
        for(int i=0; i<n; i++)
        {
            if(arr[i] != n-i)
            {
                int index = pos[n-i];
                int temp = arr[i];
                arr[i] = arr[index];
                arr[index] = temp;
                pos[temp] = index;
                k--;
                if(k==0)
                    break;
            }
        }
    }


int main(){
    int n, k;
    cin>>n>>k;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<solve(arr, n, k)<<endl;
    return 0;
}