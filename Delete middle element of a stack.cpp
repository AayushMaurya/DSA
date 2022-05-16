// Delete middle element of a stack 

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

void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int mid=ceil((sizeOfStack+1)*1.0/2);
        // cout<<mid<<endl;
        stack<int> st;
        while(mid)
        {
            if(mid!=1)
                st.push(s.top());
            s.pop();
            mid--;
        }
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