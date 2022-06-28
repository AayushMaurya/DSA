// Group anagram

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

 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;
        
        for(auto itr: strs)
        {
            string temp = itr;
            sort(temp.begin(), temp.end());
            
            mp[temp].push_back(itr);
        }
        vector<vector<string>> ans;
        
        for(auto itr: mp)
        {
            ans.push_back(itr.second);
        }
        
        return ans;
    }