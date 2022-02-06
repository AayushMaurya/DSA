// Transfiguration

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

int solve()
{
    string A, B;
    cin>>A>>B;

    if(A.length()!=B.length())
        return -1;

    int n=A.length();
    map<char, int> mp;
    for(int i=0; i<n; i++)
    {
        mp[A[i]]++;
        mp[B[i]]--;
    }

    for(auto itr=mp.begin(); itr!=mp.end(); itr++)
        if(itr->second!=0)
            return -1;

    int res=0;
    int j=n-1;
    
    for(int i=n-1; i>=0; i--)
    {
        if(A[i]==B[j])  j--;
        else    res++;
    }

    return res;
}

int main(){
    cout<<solve()<<endl;
    return 0;
}