// Minimum Deletions to Make Character Frequencies Unique

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

int minDeletions(string s) {
        unordered_map<char, int> mp;
        
        for(auto itr: s)
            mp[itr]++;
        
        int highest_freq = 0;
        
        unordered_map<int, int> freq;
        
        for(auto itr: mp)
        {
            freq[itr.second]++;
            highest_freq = max(highest_freq, itr.second);
        }
        
        int ans=0;
        while(highest_freq>0)
        {
            if(freq[highest_freq] <=1){
                highest_freq--;
                continue;
            }
            
            int extra = freq[highest_freq]-1;
            
            ans+=extra;
            
            highest_freq--;
            
            freq[highest_freq] += extra;
        }
        
        return ans;
        
    }