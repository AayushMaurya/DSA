// count prefix of given string

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

int countPrefixes(vector<string>& words, string s) {
        int ans=0;
        for(int i=0; i<words.size(); i++)
        {
            if(words[i].size() <= s.size() && s.substr(0, words[i].size()) == words[i])
                ans++;
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