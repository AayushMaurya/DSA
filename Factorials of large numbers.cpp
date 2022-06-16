// Factorials of large numbers

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

vector<int> factorial(int N){
        vector<int> ans;
        if(N==0)
            return ans;
            
        ans.push_back(1);
        int carry=0;
        int j, prod;
        for(int i=2; i<=N; i++)
        {
            for(j=0; j<ans.size(); j++)
            {
                prod=ans[j]*i + carry;
                ans[j] = prod%10;
                carry = prod/10;
            }
            while(carry>0)
            {
                ans.push_back(carry%10);
                carry = carry/10;
            }
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