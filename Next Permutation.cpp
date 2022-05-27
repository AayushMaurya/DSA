// Next Permutation
// built-in function next_permutation(arr.begin(), arr.end())

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

 void nextPermutation(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        int i, x;
        for(i=n-1; i>=0; i--)
        {
            st.insert(nums[i]);
            auto itr = st.find(nums[i]);
            itr++;
            if(itr!=st.end())
            {
                x=*itr;
                break;
            }
        }
        if(i==-1)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        for(int j=n-1; j>=0; j--)
        {
            if(nums[j] == x){
                x=j;
                break;
            }
        }
        int temp=nums[x];
        nums[x] = nums[i];
        nums[i] = temp;
        sort(nums.begin()+i+1, nums.end());
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}