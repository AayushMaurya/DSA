// Tower of Hanoi

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


long long toh(int N, int from, int to, int aux) {
    int ans=0;
    if(N>0)
    {
        ans+=toh(N-1, from, aux, to);
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        ans++;
        ans+=toh(N-1, aux, to, from);
    }
    return ans;

int main(){
    
    int n;
    cin>>n;
vector<vector<int>> vec(n, vector<int>(n));
for(int i=0; i<n; i++)
    cin>>vec[i][0]>>vec[i][1];

cout<<solve(vec, n, n)<<endl;
    return 0;
}