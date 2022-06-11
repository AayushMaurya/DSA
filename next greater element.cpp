// next greater element

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

vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<int> st;
        
        // st.push(0);
        for(int i=0; i<n; i++)
        {
            if(st.empty() || arr[st.top()] > arr[i])
                st.push(i);
            else{
                while(!st.empty() && arr[st.top()] < arr[i])
                {
                    arr[st.top()] = arr[i];
                    st.pop();
                    
                }
                st.push(i);
            }
        }
        while(!st.empty())
        {
            arr[st.top()] = -1;
            st.pop();
        }
        return arr;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}