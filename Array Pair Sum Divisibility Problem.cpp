// Array Pair Sum Divisibility Problem

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

bool canPair(vector<int> nums, int k) {
        
        vector<int> count(k, 0);
        
        for(int i=0; i<nums.size(); i++)
            count[nums[i]%k]++;
            
        for(int i=0; i<k; i++)
        {
            if(i==0)
            {
                if(count[i]%2!=0)
                    return false;
            }
            else if(i==k-i)
            {
                if(count[i]%2!=0)
                    return false;
            }
            else
            {
                if(count[i]!=count[k-i])
                    return false;
            }
        }
        return true;
    }