// Palindrome partitioning

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

bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
    }
    
    void solve(int index, string s, vector<vector<string>>& ans, vector<string>& res)
    {
        if(index==s.size())
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=index; i<s.size(); i++)
        {
            if(isPalindrome(s, index, i))
            {
                res.push_back(s.substr(index, i-index+1));
                solve(i+1, s, ans, res);
                res.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        
        solve(0, s, ans, res);
        
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}