// Anagram 

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

bool isAnagram(string a, string b){
        
        vector<int> vec(26, 0);
        if(a.size()!=b.size())
            return false;
        
        for(int i=0; i<a.size(); i++)
        {
            vec[a[i]-'a']++;
            vec[b[i]-'a']--;
        }
        
        for(auto itr:vec)
        {
            if(itr!=0)
                return false;
        }
        return true;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}