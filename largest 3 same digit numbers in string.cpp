// largest 3 same dight number in string

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

 string largestGoodInteger(string num) {
        string ans="";
        
        for(int i=0; i<num.size()-2; i++)
        {
            if(num[i] == num[i+1] && num[i] == num[i+2])
            {
                ans = max(ans, num.substr(i, 3));
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