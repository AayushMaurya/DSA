// Sort array of 0's, 1's and 2's

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

void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start=0, end=n-1, i=0;
        while(i<=end)
        {
            if(nums[i] == 0)
            {
                swap(nums[start], nums[i]);
                i++;
                start++;
            }
            else if(nums[i] == 1)
                i++;
            else
            {
                swap(nums[end], nums[i]);
                end--;
            }
        }
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}