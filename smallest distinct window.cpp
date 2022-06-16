// smallest distinct window

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

int findSubString(string str)
    {
        unordered_map<char, int> mp;
        set<char> st;
        int ans = str.size();
        for(int i=0; i<str.size(); i++)
            st.insert(str[i]);
            
        int n = st.size();
        
        int j=0;
        for(int i=0; i<str.size(); i++)
        {
            mp[str[i]]++;
            
            while(mp[str[j]] > 1)
            {
                mp[str[j]]--;
                j++;
            }
            
            if(mp.size()==n)
            {
                ans = min(ans, i-j+1);
            }
        }
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}