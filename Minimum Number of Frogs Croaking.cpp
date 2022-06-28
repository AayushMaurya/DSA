// Minimum Number of Frogs Croaking

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

int minNumberOfFrogs(string c) {
        
        map<char, int> mp;
        
        for(int i=0; i<c.size(); i++)
        {
            mp[c[i]]++;
            if(mp['k']>mp['a'] || mp['a']>mp['o'] || mp['o']>mp['r'] || mp['r']>mp['c'])
                return -1;
        }
        
        int t = mp['c'];
        
        for(auto itr: mp)
        {
            if(itr.second!=t)
                return -1;
        }
        
        int ans=0;
        int count=0;
        
        for(int i=0; i<c.size(); i++)
        {
            if(c[i] == 'c')
                count++;
            else if(c[i] == 'k')
                count--;
            ans = max(ans, count);
        }
        return ans;
    }