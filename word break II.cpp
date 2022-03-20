// Word Break II

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

unordered_map<string, int> mp;

    bool check(string s, vector<string>& wordDict)
    {
        if(s.length() > 20)
            return false;
        else
            for(auto str: wordDict)
            {
                if(str == s)
                    return true;
            }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        if(mp[s] == 1)
            return true;
        else if(mp[s] == -1)
            return false;
        
        int n=s.length();
        if(n <= 20)
        {
            for(auto str: wordDict)
            {
                if(str == s){
                    mp[s] = 1;
                    return true;
                }
            }
        }
            for(int i=0; i<n; i++)
            {
                if(check(s.substr(0, i+1), wordDict) && wordBreak(s.substr(i+1, n-i-1), wordDict))              {
                    mp[s] = 1;
                    return true;
                }
            }
        mp[s] = -1;
        return false;
    }

int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;

    vector<string> wordDict(n);
    for(int i=0; i<n; i++)
        cin>>wordDict[i];

    cout<<wordBreak(s, wordDict)<<endl;
    return 0;
}