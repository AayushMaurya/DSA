// Sum of elements between k1'th and k2'th smallest elements

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

long long sumBetweenTwoKth( long long A[], long long N, long long k1, long long k2)
    {
        priority_queue<long long> smallest;
        priority_queue<long long, vector<long long>, greater<long long>> largest;
        
        long long sums=0, suml=0, sum=0;
        k2 = N+1-k2;
        
        for(int i=0; i<N; i++)
        {
            long long itr = A[i];
            sum += itr;
            largest.push(itr);
            suml += itr;
            smallest.push(itr);
            sums += itr;
            
            if(smallest.size()>k1)
            {
                sums -= smallest.top();
                smallest.pop();
            }
            
            if(largest.size() > k2)
            {
                suml -= largest.top();
                largest.pop();
            }
        }
        
        return sum - (sums+suml);
    }