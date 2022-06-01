// Longest substring without repeat

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

int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0, j=0;
        map<char, int> mp;
        int ans=0;
        for(j=0; j<s.size(); j++)
        {
            int x=mp[s[j]];
            if(x==n)
                x=0;
            if(mp[s[j]] && x >= i)
            {
                i=x+1;
                mp[s[j]] = j;
            }
            else {
                mp[s[j]] = j;
                if(j==0)
                    mp[s[j]]=n;
                ans = max(ans, j-i+1);
            }
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