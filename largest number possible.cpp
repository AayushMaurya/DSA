// Largest Number Possible

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
    int N, S;
    cin>>N>>S;

    string res="";
        if(S == 0 && N>1)
            {
                cout<<"-1"<<endl;
                return;
            }
        for(int i=0; i<N; i++)
        {
            if(S<9){
                char c = '0' + S;
                res = res + c;
                S = 0;
            }
            else
            {
                res = res + "9";
                S = S-9;
            }
        }
        if(S > 0)
            res =  "-1";
        cout<<res<<endl;

    return;
}

int main(){
    solve();
    return 0;
}