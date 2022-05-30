// Majority Element > N/2
// using stack

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

int majorityElement(vector<int>& nums) {
        stack<int> st;
        st.push(nums[0]);
        for(int i=1; i<nums.size(); i++)
        {
            if(st.empty() || nums[i] == st.top())
                st.push(nums[i]);
            else
                st.pop();
        }
        int count=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(st.top() == nums[i])
                count++;
        }
        if(count >= nums.size()/2);
            return st.top();
        return -1;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}