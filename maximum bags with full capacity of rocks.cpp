// Maximum bags with full capacity of rocks

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

int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        
        vector<int> rem(n);
        
        for(int i=0; i<n; i++)
            rem[i] = capacity[i]-rocks[i];
        
        sort(rem.begin(), rem.end());
        
        for(int i=0; i<n; i++)
        {
            if(additionalRocks<rem[i])
                return i;
            additionalRocks-=rem[i];
        }
        return n;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}