// Plus one

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

vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        int carry=0;
        
        if(digits[n-1] < 9)
        {
            digits[n-1]++;
            return digits;
        }
        
        int temp = digits[n-1]+1;
        carry = temp/10;
        ans.push_back(temp%10);
        
        for(int i=n-2; i>=0; i--)
        {
            temp = digits[i] + carry;
            carry = temp/10;
            ans.push_back(temp%10);
        }
        
        if(carry>0)
            ans.push_back(carry);
        
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