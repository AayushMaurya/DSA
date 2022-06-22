// Count subsequences of type a^i, b^j, c^k

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

int fun(string &s) {
        
        long long a=0, ab=0, abc=0;
        
        for(auto itr: s)
        {
            if(itr == 'a')
                a = (a*2 + 1)%1000000007;
            else if(itr == 'b')
                ab = (ab*2 + a)%1000000007;
            else if(itr == 'c')
                abc = (abc*2 + ab)%1000000007;
        }
        return (int)abc;
    }