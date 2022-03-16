// Choose and swap

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
    string s;
    cin>>s;

    set<char> st;
    for(int i=0; i<s.length(); i++)
        st.insert(s[i]);

    for(int i=0; i<s.length(); i++)
    {
        st.erase(s[i]);
        if(st.empty())
            break;
        char ch1 = *st.begin();
        if(s[i] > ch1)
        {
            char ch2 = s[i];
            for(int i=0; i<s.length(); i++)
            {
                if(s[i] == ch1)
                    s[i] = ch2;
                else if(s[i] == ch2)
                    s[i] = ch1;
            }
            break;
        }
    }
    cout<<s<<endl;

    return;
}

int main(){
    solve();
    return 0;
}