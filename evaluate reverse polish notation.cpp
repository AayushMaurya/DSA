// Evaluate reverse polish notation

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

int evalRPN(vector<string>& tokens) {
        
        stack<string> st;
        
        if(tokens.size() == 0)
            return 0;
        
        // st.push(tokens[0]);
        int i=0;
        
        while(i<tokens.size())
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int b = stoi(st.top());
                st.pop();
                int a = stoi(st.top());
                st.pop();
                
                int ans;
                if(tokens[i] == "+")
                    ans = a+b;
                else if(tokens[i] == "-")
                    ans = a-b;
                else if (tokens[i] == "*")
                    ans = a*b;
                else
                    ans = a/b;
                
                st.push(to_string(ans));
                
                i++;
            }
            else{
                st.push(tokens[i]);
                i++;
            }
        }
        
        return stoi(st.top());
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}