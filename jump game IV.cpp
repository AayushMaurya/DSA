// Jump game IV

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
# define pii pair<int, int>
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

int maxResult(vector<int>& nums, int k) {
        
        multiset<int> st;
        st.insert(nums[0]);
        
        for(int i=1; i<nums.size(); i++)
        {
            nums[i] = *st.rbegin() + nums[i];
            
            st.insert(nums[i]);
            if(st.size() > k)
            {
                auto it = st.find(nums[i-k]);
                st.erase(it);
            }
        }
        
        return *nums.rbegin();
    }