// Fact Digit Sum

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

vector<int> FactDigit(int N)
    {
        vector<int> res;
        
        int fact[10];
        int f = 1;
        for(int i=1; i<=9; i++)
        {
            fact[i] = f*(i);
            f=f*i;
           // cout<<fact[i]<<" ";
        }
        int index=9;
        while(N){
           while(fact[index] <= N)
           {
               N=N-fact[index];
               res.push_back(index);
           }
           index--;
        }
        reverse(res.begin(), res.end());
        return res;
    }

int main(){
    int n;

    cin>>n;

    cout<<FactDigit(n)<<endl;
    return 0;
}