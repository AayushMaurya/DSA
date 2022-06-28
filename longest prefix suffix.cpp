// Longest prefix suffix
// KMP algorithm

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

int lps(string s) {
        
        int n = s.size();
        vector<int> lps(n);
        int i=1;
        int len=0;
        lps[0]=0;
        
        while(i<n)
        {
            if(s[i] == s[len])
            {
                lps[i] = len+1;
                len++;
                i++;
            }
            else
            {
                if(len!=0)
                {
                    len = lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        
        return lps[n-1];
    }