// check wheter one string is rotation of another

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


int substr(string a, string b)
{
    int counter = 0;
    int i=0;

    for(i ; i<a.length() ; i++)
    {
        if(counter == b.length())
            break;

        if(b[counter] == a[i])
            counter++;

        else{
            if(counter > 0)
                i -= counter;

            counter=0;
        }
    }

    if(counter<b.length())
        return 1;
    else return 0;
}

void solve()
{
    string a, b;
    cin>>a>>b;

    if(a.length() != b.length())
    {
        cout<<"No"<<endl;
        return;
    }

    string temp = b + b;
    // cout<<temp<<endl;

    if(substr(a, temp))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return;
}

int main()
{
	solve();
	return 0;
}