// Non decreasing array

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

bool checkPossibility(vector<int>& nums) {
        int flag=0;
        
        if(nums.size()<=2)
            return true;
        
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] < nums[i-1])
            {
                flag++;
                if(i-2<0 || nums[i-2]<=nums[i])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
            }
        }
        
        return flag<=1;
    }