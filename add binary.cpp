// Add binary

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

string addBinary(string a, string b) {
        
        int i=a.size()-1, j=b.size()-1;
        int carry=0;
        string ans="";
        
        while(i>=0 && j>=0)
        {
            int sum = a[i--]-'0' + b[j--]-'0' + carry;
            carry = sum/2;
            sum = sum%2;
            ans+=sum+'0';
        }
        
        while(i>=0)
        {
           int sum = a[i--]-'0' + carry;
            carry = sum/2;
            sum = sum%2;
            ans+=sum+'0';
        }
        
        while(j>=0)
        {
            int sum = b[j--]-'0' + carry;
            carry = sum/2;
            sum = sum%2;
            ans+=sum+'0';
        }
        
        if(carry == 1)
            ans+="1";
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}