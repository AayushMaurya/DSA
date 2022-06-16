// Maximum index

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

int maxIndexDiff(int A[], int N) 
    { 
        int leftmin[N];
        leftmin[0] = A[0];
        
        int rightmax[N];
        rightmax[N-1] = A[N-1];
        
        for(int i=1; i<N; i++)
            leftmin[i] = min(leftmin[i-1], A[i]);
            
        for(int i=N-2; i>=0; i--)
            rightmax[i] = max(rightmax[i+1], A[i]);
            
        int i=0, j=0;
        int ans = -1;
        while(i<N && j<N)
        {
            if(leftmin[i] <= rightmax[j])
            {
                ans = max(ans, j-i);
                j++;
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