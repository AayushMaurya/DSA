// minimum index character

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

int minIndexChar(string str, string patt)
    {
        vector<int> v(26, 0);
        for(int i=0; i<patt.size(); i++)
            v[patt[i]-'a']++;
        
        for(int i=0; i<str.size(); i++)
        {
            if(v[str[i]-'a']>0)
                return i;
        }
        return -1;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}