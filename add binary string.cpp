// Add binary string

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

string addBinary(string A, string B)
    {
        int i=A.size()-1, j=B.size()-1;
        
        string ans="";
        int carry = 0;
        
        while(i>=0 || j>=0 || carry)
        {
            int a=0, b=0;
            if(i!=-1)
            {
                a = A[i--]-'0';
            }
            
            if(j!=-1)
            {
                b = B[j--]-'0';
            }
            
            int x = carry + a + b;
            ans += to_string(x%2);
            carry = x/2;
        }
        
        int k = ans.size()-1;
        
        while(ans[k]!='1')
        {
            k--;
            ans.pop_back();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }