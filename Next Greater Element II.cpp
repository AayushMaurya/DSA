// Next Greater Element II

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

vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, -1);
        
        for(int i=0; i<n; i++)
        {
            if(st.empty() || nums[st.top()] > nums[i])
            {
                st.push(i);
            }
            else{
                while(!st.empty() && nums[i] > nums[st.top()])
                {
                    ans[st.top()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        
        int i=0;
        
        while(!st.empty() && i<n)
        {
            while(!st.empty() && nums[i] > nums[st.top()])
            {
                ans[st.top()] = nums[i];
                st.pop();
            }
            i++;
        }
        
        return ans;
    }