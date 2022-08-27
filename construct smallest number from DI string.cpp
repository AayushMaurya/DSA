// construct smallest number from DI string

include<bits/stdc++.h>
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

// **********************************

string smallestNumber(string pattern) {
        stack<int> st;
        int num = 1;
        st.push(num);
        num++;
        
        string ans = "";
        
        for(int i=0; i<pattern.size(); i++)
        {
            if(pattern[i] == 'I')
            {
                while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
                st.push(num);
                num++;
            }
            else{
                st.push(num);
                num++;
            }
        }
        while(!st.empty()){
            ans += to_string(st.top());
            st.pop();
        }
        return ans;
    }