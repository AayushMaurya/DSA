// Sort a stack 

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

void SortedStack :: sort()
{
    if(s.empty())
        return;
    if(s.size() == 1)
        return;
   int temp = s.top();
   s.pop();
   sort();
   stack<int> st;
   while(!s.empty() && s.top()>temp)
   {
       st.push(s.top());
       s.pop();
   }
   s.push(temp);
   while(!st.empty())
   {
       s.push(st.top());
       st.pop();
   }
}


int main(){
    
solve();
    return 0;
}