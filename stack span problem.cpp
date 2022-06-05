// stack span problem

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

vector <int> calculateSpan(int price[], int n)
    {
        vector<int> ans;
        stack<int> st;
        st.push(-1);
        st.push(0);
        ans.push_back(1);
        for(int i=1; i<n; i++)
        {
            while(st.top()!=-1 && price[st.top()]<=price[i])
                st.pop();
            ans.push_back(i-st.top());
            st.push(i);
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