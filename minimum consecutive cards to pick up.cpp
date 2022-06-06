// minimum consecutive cards to pickup

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

int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        unordered_map<int, int> mp;
        mp[cards[0]] = n;
        int ans=INT_MAX;
        for(int i=1; i<n; i++)
        {
            if(mp[cards[i]])
            {
                int x=mp[cards[i]];
                if(x==n)
                    x=0;
                ans = min(ans, i-x+1);
            }
            mp[cards[i]] = i;
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}