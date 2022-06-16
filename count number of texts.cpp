// Count number of texts

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

int countTexts(string str) {
        vector<long long> d3(100001, 0);
        vector<long long> d4(100001, 0);
        
        d3[1] = 1;
        d3[2] = 2;
        d3[3] = 4;
        
        d4[1] = 1;
        d4[2] = 2;
        d4[3] = 4;
        d4[4] = 8;
        
        for(int i=4; i<=100000; i++)
            d3[i] = (d3[i-1] + d3[i-2] + d3[i-3])%1000000007;
        for(int i=5; i<=100000; i++)
            d4[i] = (d4[i-1] + d4[i-2] + d4[i-3] + d4[i-4])%1000000007;
        
        long long ans = 1;
        int i=0, j;
        
        while(i<str.size())
        {
            j = i+1;
            while(j<str.size() && str[j] == str[i]) 
                j++;
            
            if(str[i] == '7' || str[i] == '9')
                ans = (ans * d4[j-i])%1000000007;
            else
                ans = (ans * d3[j-i])%1000000007;
                
            i=j;
        }
        return (int)ans%1000000007;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}