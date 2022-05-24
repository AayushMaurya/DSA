// Wiggle subsequence
// Greedy

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


int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1)    return 1;
        
        int prev_dis = nums[1] - nums[0];
        int count = (prev_dis!=0) ? 2: 1;
        
        for(int i=2; i<nums.size(); i++)
        {
            int curr = nums[i] - nums[i-1];
            if(curr>0 && prev_dis <= 0 || curr<0 && prev_dis>=0)
            {
                count++;
                prev_dis = curr;
            }
        }
        return count;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}