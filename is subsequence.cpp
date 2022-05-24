// Is Subsequence

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


ibool isSubsequence(string s, string t) {
        int i=0, j=0;
        for(int i=0; i<t.size(); i++)
        {
            if(j>=s.size())
                return true;
            if(t[i] == s[j])
                j++;
        }
        if(j>=s.size())
            return true;
        return false;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}