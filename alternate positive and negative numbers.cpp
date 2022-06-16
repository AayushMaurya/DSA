// Alternate positive and negative numbers

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

void rearrange(int arr[], int n) {
        vector<int> pos;
        vector<int> neg;
        
        for(int i=0; i<n; i++)
        {
            if(arr[i]<0)
                neg.push_back(arr[i]);
           else
            pos.push_back(arr[i]);
        }
        
        int i=0, j=0, k=0;
        
        while(i<n)
        {
            if(j<pos.size())
                arr[i++] = pos[j++];
           if(k<neg.size())
                arr[i++] = neg[k++];
        }
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}