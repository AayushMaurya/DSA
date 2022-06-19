// Daily temperature
// https://leetcode.com/problems/daily-temperatures/

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

vector<int> dailyTemperatures(vector<int>& t) {
        
        stack<int> st;
        vector<int> ans(t.size(), 0);
        
        int n = t.size()-1;
        
        while(n>=0)
        {
            if(st.empty())
                st.push(n);
            else{
                while(!st.empty() && t[st.top()]<=t[n])
                {
                    st.pop();
                }
                if(!st.empty())
                    ans[n] = st.top()-n;
                st.push(n);
            }
            n--;
        }
        
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}