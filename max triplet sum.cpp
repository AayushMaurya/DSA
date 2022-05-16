// Max triplet sum

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

int Solution::solve(vector<int> &A) {
    int ans=0;
    int n = A.size();
    if(n<3)
        return 0;
    vector<int> right(n);
    for(int i=n-1; i>=0; i--)
    {
        if(i==n-1)  right[n-1]=A[n-1];
        else    right[i] = max(right[i+1], A[i+1]);
    }
    set<int> st;
    st.insert(A[0]);
    for(int i=1; i<n; i++)
    {
        st.insert(A[i]);
        auto itr = st.find(A[i]);
        if(itr!=st.begin() && right[i]!=A[i] && right[i]>A[i])    
            ans = max(ans, (*--itr) + A[i] + right[i]);
    }

    return ans;
}


int main(){
    
solve();
    return 0;
}