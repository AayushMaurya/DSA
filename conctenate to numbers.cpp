// Contatenate two numbers 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
// ll max(ll x, ll y)
// {
//     return (x>y)?x:y;
// }
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

void solve()
{
    int N, X;
    cin>>N>>X;

    int numbers[N];
    for(int i=0; i<N; i++)
        cin>>numbers[i];

    unordered_map<string, int> mp;
        for(int i=0; i<N; i++)
            mp[to_string(numbers[i])]++;
        
        string x=to_string(X);
        long long int res=0;
        
        for(int i=1; i<x.size(); i++)
        {
            string first=x.substr(0, i);
            string second=x.substr(i, x.size());
            if(first==second)
                res+=mp[first]*(mp[second]-1);
            else
                res+=mp[first]*mp[second];
        }
        cout<<res<<endl;

    return;
}

int main(){
    solve();
    return 0;
}