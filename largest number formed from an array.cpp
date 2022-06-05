// largest number formed from an array

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

static bool comparaison(string a, string b)
    {
        return a+b>b+a;
    }
    
    string printLargest(vector<string> &arr) {
        
        sort(arr.begin(), arr.end(), comparaison);
        
        string ans="";
        
        for(auto itr: arr)
            ans+=itr;
        
        return ans;        
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}