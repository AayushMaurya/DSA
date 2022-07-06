// Longest Consecutive Sequence

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

int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_set<int> record(nums.begin(), nums.end());
        
        int res=1;
        for(int n: nums)
        {
            if(record.find(n)==record.end())    continue;
            record.erase(n);
            
            int prev=n-1, next = n+1;
            
            while(record.find(prev)!=record.end())  record.erase(prev--);
            while(record.find(next)!=record.end())  record.erase(next++);
            
            res = max(res, next-prev-1);
        }
        
        return res;
    }