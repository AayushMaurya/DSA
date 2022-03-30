// Minimum swap for Bracket Balancing

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

int solve(string S){
        int temp = 0;
        int res=0;
        for(int i=0; i<S.length(); i++)
        {
            if(temp<0 && S[i] == '[')
                res += abs(temp);
            if(S[i] == '[')
                temp++;
            else
                temp--;
            
        }
        return res;
    }


int main(){
    string S;

    cin>>S;

    cout<<solve(S)<<endl;
    return 0;
}