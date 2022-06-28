// Check if two strings are k-anagrams or not

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

bool areKAnagrams(string str1, string str2, int k) {
        
        if(str1.size()!=str2.size())
            return false;
            
        vector<int> count(26, 0);
        
        for(int i=0; i<str1.size(); i++)
        {
            count[str1[i]-'a']++;
            count[str2[i]-'a']--;
        }
        
        int sum=0;
        for(int i=0; i<26; i++)
        {
            sum += abs(count[i]);
        }
        if(sum > k*2)
            return false;
        return true;
    }