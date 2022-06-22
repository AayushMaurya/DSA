// Short Encoding of Words
// Reverse each word and sord words

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

int minimumLengthEncoding(vector<string>& words) {
        
        int n = words.size();
        
        for(int i=0; i<n; i++)
            reverse(words[i].begin(), words[i].end());
        
        sort(words.begin(), words.end());
        
        int ans=0;
        for(int i=0; i<n-1; i++)
        {
            if(words[i] != words[i+1].substr(0, words[i].size()))
                ans += words[i].size() + 1;
        }
        ans += words[n-1].size() + 1;
        return ans;
    }