// Smallest window containing 0, 1 and 2

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
// ll max(ll x, ll y)
// {
//     return (x>y)?x:y;
// }
// ll min(ll x, ll y)
// {
//     return (x>y)?y:x;
// }
void swap(ll *x, ll *y)
{
    ll temp = *x;
    *x = *y;
    *y = temp;
}

int solve()
{
    string s;
    cin>>s;

    int res=INT_MAX;
    int j=0, a=0, b=0, c=0;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '0')
            a++;
        else if(s[i] == '1')
            b++;
        else if(s[i] == '2')
            c++;

        while(a>0 && b>0 && c>0)
        {
            res=min(res, i-j+1);
            if(res==3)
                return 3;

            if(s[j] == '0')
                a--;
            else if(s[j] == '1')
                b--;
            else if(s[j] == '2')
                c--;
            j++;
        }
    }
    if(res== INT_MAX)
        return -1;
    return res;
}

int main(){
    cout<<solve()<<endl;
    return 0;
}