// Distribute N candies among K people

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

vector<long long> distributeCandies(int N, int K) {
        vector<long long > ans(K, 0);
        
        int i=0;
        long long count=0;
        
        while(N)
        {
            if(count >= N)   count=N;
            else    count++;
            ans[i++] += count;
            N -= count;
            if(i==K)    i=0;
            
        }
        return ans;
    }