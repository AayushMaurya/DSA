// Short Encoding of Words

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

bool suffix(string &a, string &b)
    {
        if(b.substr(b.size()-a.size()) == a)
            return true;
        return false;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        
        int n = words.size();
        vector<bool> visited(n, false);
        
        int ans=0;
        
        for(int i=0; i<n; i++)
        {
            if(visited[i])  continue;
            
            visited[i] = true;
            string s = words[i];
            
            for(int j=0; j<n; j++)
            {
                if(visited[j])  continue;
                
                if(words[j].size() < s.size())
                {
                    if(suffix(words[j], s))
                        visited[j] = true;
                }
                else{
                    if(suffix(s, words[j]))
                    {
                        visited[j] = true;
                        s = words[j];
                    }
                }
            }
            
            ans += 1 + s.size();
        }
        return ans;
    }