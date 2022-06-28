// Find All Anagrams in a String

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

vector<int> findAnagrams(string s, string p) {
        
        vector<int> pash(26, 0);
        vector<int> hash(26, 0);
        
        vector<int> ans;
        
        if(s.size()<p.size())
            return ans;
        
        for(int i=0; i<p.size(); i++)
        {
            pash[p[i]-'a']++;
            hash[s[i]-'a']++;
        }
        
        if(pash == hash)
            ans.push_back(0);
        
        for(int i=p.size(); i<s.size(); i++)
        {
            hash[s[i]-'a']++;
            hash[s[i-p.size()]-'a']--;
            
            if(hash == pash)
                ans.push_back(i-p.size()+1);
        }
        return ans;
    }