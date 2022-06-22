// Smallest window in a string containing all the characters of another string

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

string smallestWindow (string s, string p)
    {
        unordered_map<char, int> mp;
        int count=0;
        for(auto itr: p){
            if(mp[itr] == 0)
                count++;
            mp[itr]++;
        }
            
        int len = -1;    
        int n = s.size();
        int start, i=0;
        for(int j=0; j<n; j++)
        {
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }
            
            while(count==0)
            {
                if(len > j-i+1 || len==-1)
                {
                    start = i;
                    len = j-i+1;
                }
                
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1)
                        count++;
                }
                i++;
            }
            
        }
        if(len == -1)
                return "-1";
            
        return s.substr(start, len);
    }