// Reverse word in a string

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

void reverse(string& s, int i, int j)
    {
        while(i<j)
        {
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
    }
    
    string reverseWords(string s) {
        int i=0, j=0, l=0;
        int len = s.size();
        
        int count=0;
        while(true)
        {
            while(i<len && s[i] == ' ') i++;
            if(i==len)  break;
            
            if(count)   s[j++] = ' ';
            l = j;
            
            while(i<len && s[i]!=' '){
                s[j] = s[i];
                i++; j++;
            }
            
            reverse(s, l, j-1);
            count++;
        }
        
        s.resize(j);
        
        reverse(s, 0, j-1);
        
        return s;
    }