// Word Break part II

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

void solve(string s, vector<string>& ans, map<string, int>& mp, string res)
    {
        if(s.size()==0)
        {
            res.pop_back();
            ans.push_back(res);
            return ;
        }
        
        for(int i=0; i<s.size(); i++)
        {
            string temp = s.substr(0, i+1);
            if(mp[temp])
            {
                temp += " ";
                solve(s.substr(i+1), ans, mp, res+temp);
            }
        }
        
        return;
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> ans;
        
        map<string, int> mp;
        
        for(auto str: dict)
            mp[str]++;
            
        solve(s, ans, mp, "");
        
        return ans;
    }