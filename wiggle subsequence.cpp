// Wiggle subsequence

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
        int inc, dec;
        inc=1, dec=1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
                inc = dec+1;
            else if(nums[i] < nums[i-1])
                dec = inc+1;
        }
        return max(inc, dec);
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}