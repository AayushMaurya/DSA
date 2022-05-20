#include<bits/stdc++.>
using namespace std;
#define ll long long int

void solve() {
    ll N;
    ll multiples_of_3, multiples_of_5, multiples_of_15;
    ll sum;
    
    cin>>N;
    multiples_of_3 = (N-1)/3;
    multiples_of_5 = (N-1)/5;
    multiples_of_15 = (N-1)/15;

    sum = 3*multiples_of_3*(multiples_of_3+1)/2 + 5*multiples_of_5*(multiples_of_5+1)/2 + 15*multiples_of_15*(multiples_of_15+1)/2;
   
    cout<<sum<<endl;  

}

int main()
{
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
