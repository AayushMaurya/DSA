// Find and replace pattern

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

vector<int> find(string& word)
    {
        unordered_map<char, int> mp;
        int counter = 0;
        vector<int> ans;
        
        for(int i=0; i<word.size(); i++)
        {
            if(mp.find(word[i])==mp.end())
            {
                counter++;
                mp[word[i]] = counter;
                ans.push_back(mp[word[i]]);
            }
            else
                ans.push_back(mp[word[i]]);
        }
        
        return ans;
    }
   
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<int> v = find(pattern);
        
        vector<string> ans;
        for(auto word: words)
        {
            vector<int> p = find(word);
            
            if(v==p)
                ans.push_back(word);
        }
        return ans;
    }