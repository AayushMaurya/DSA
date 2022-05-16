// decode ways

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

int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int cur=1, pre=1;
        for(int i=1; i<s.size(); ++i) {
            if(s[i]=='0') {
                if(s[i-1]!='1' && s[i-1]!='2') return 0;
                cur = pre;
            }
            else if(s[i-1]=='1' || (s[i-1]=='2' && s[i]<'7')) {
                cur += pre;
                pre = cur-pre;
            }
            else pre = cur;
        }
        return cur;
    }

int main(){
    
solve();
    return 0;
}