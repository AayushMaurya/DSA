// String formation from substring

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

int isRepeat(string s)
    {
        string temp = "";
        for(int i=0; i<s.size()/2; i++)
        {
            temp += s[i];
            
            if(s.size()%temp.size() != 0)
                continue;
           
            int n = s.size()/temp.size();
            string curr = "";
            for(int i=0; i<n; i++)
                curr += temp;
            if(curr == s)
                return 1;
        }
        return 0;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}