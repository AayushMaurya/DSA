#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int hcf(int a, int b)
{
    if(b == 0)  return a;
    return hcf(b, a%b);
}

int lcm(int a, int b)
{
    return a*b/hcf(a, b);
}

void solve()
{
    int n, res=1;
    cin>>n;
    
    for(int i=2 ; i<=n ; i++)
    {
        res = lcm(i, res);
    }
    cout<<res<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }   
    return 0;
}
