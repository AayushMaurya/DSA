// Recursively remove all adjacent duplicates

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


string rremove(string s){;
        int n=s.size();
        if(n<=1)
            return s;
        string ans="";
        if(s[0]!=s[1])
            ans+=s[0];
        for(int i=1; i<n-1; i++)
        {
            if(s[i] == s[i-1] || s[i] == s[i+1])
                continue;
            ans+=s[i];
        }
        if(s[n-1] != s[n-2])
            ans+=s[n-1];
        if(n==ans.size())
            return s;
        return rremove(ans);
    }

int main(){
    
    int n;
    cin>>n;
vector<vector<int>> vec(n, vector<int>(n));
for(int i=0; i<n; i++)
    cin>>vec[i][0]>>vec[i][1];

cout<<solve(vec, n, n)<<endl;
    return 0;
}