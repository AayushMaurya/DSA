// Add to array form of integer

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

vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int carry = k;
        reverse(num.begin(), num.end());
        for(auto itr: num)
        {
            int sum = itr + carry;
            carry = sum/10;
            ans.push_back(sum%10);
        }
        
        while(carry)
        {
            ans.push_back(carry%10);
            carry = carry/10;
        }
        
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