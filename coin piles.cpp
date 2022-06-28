// Coin Piles

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

int minSteps(int A[], int N, int k) {
        
        sort(A, A+N);
        
        vector<int> prefix(N);
        prefix[0] = A[0];
        
        int ans = INT_MAX;
        
        for(int i=1; i<N; i++)
        {
            prefix[i] = prefix[i-1] + A[i];
        }
        
        int prev=0;
        
        for(int i=0; i<N; i++)
        {
            int c=1;
            while(i+1<N && A[i] == A[i+1]){
               i++;
               c++;
            }
            int permisible = A[i] + k;
            int idx = upper_bound(A, A+N, permisible)-A;
            
            int res = prefix[N-1] - prefix[idx-1];
            res -= (permisible*(N-idx));
            ans = min(ans, res+prev);
            
            prev += c*A[i];
            
        }
        return ans;
    }