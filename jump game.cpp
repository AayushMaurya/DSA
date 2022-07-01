// Jump game

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

int canReach(int A[], int N) {
        
        int last_index = N-1;
        
        for(int i=N-2; i>=0; i--)
        {
            if(A[i]+i >= last_index)
            {
                last_index = i;
            }
            
        }
        if(last_index>0)
            return 0;
        return 1;
    }