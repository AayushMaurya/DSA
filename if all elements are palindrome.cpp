// check if all the elements of an array are palindrome

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


int checkPalin(ll num)
{
    string s = to_string(num);
    ll len = s.length();

    int flag=1;

    for(ll i=0 ; i<len/2 ; i++)
    {
        if(s[i] == s[len-i-1])  continue;
        else{
            flag=0;
            break;
        }
    }
    return flag;
}

void solve()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0 ; i<n ; i++)
        cin>>arr[i];

    int flag=1;

    for(ll i=0 ; i<n ; i++)
    {
        if(checkPalin(arr[i]) == 0)
        {
            flag = 0;
            break;
        }
    }

    if(flag == 1)
        cout<<1<<endl;
    else
        cout<<0<<endl;

    return;
}

int main()
{
	solve();
	return 0;
}