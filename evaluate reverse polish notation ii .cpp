// Evaluate reverse polish notation

#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
        stack<long long int> st;
        for(int i=0; i<tokens.size(); i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*")
            {
                long long int b = st.top();
                st.pop();
                long long int a = st.top();
                st.pop();

               long long int res;

                if(tokens[i] == "+")
                    res = a + b;
                else if(tokens[i] == "-")
                    res = a-b;
                else if(tokens[i] == "*")
                    res = a*b;
                else
                    res = a/b;

               st.push(res);
            }
            else{
                long long int x = stoi(tokens[i]);
                st.push(x);
            }
        }

        return st.top();
    }