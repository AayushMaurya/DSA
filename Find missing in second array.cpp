// Find missing in second array

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

vector<long long> findMissing(long long A[], long long B[],  
                 int N, int M) 
    { 
        map<long long, int> mp;
        
        for(int i=0; i<M; i++)
        {
            mp[B[i]]=1;
        }
        
        vector<long long > ans;
        
        for(int i=0; i<N; i++)
        {
            if(mp[A[i]]!= 1)
                ans.push_back(A[i]);
           
        }
        return ans;
    } 