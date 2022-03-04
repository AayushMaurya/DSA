// Exactly one swap

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
    string S;
    cin>>S;

    long long n=S.length();
        long long total = n*(n-1)/2;
        int flag=0;
        long long freq[26] = {0};
        for(long long i=0; i<n; i++)
            freq[S[i]-'a']++;
        
        for(int i=0; i<26; i++){
            if(freq[i]>1)
                flag=1;
            total -= freq[i]*(freq[i]-1)/2;
        }
        if(flag==1)
            total++;
        cout<< total<<endl;

    return;
}

int main(){
    solve();
    return 0;
}