// Longest palindromic substring 
// Memory Optimized

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

string Solution::longestPalindrome(string s) {
    
    int n = s.size();
    
    if(n==0)
      return "";
    if(n==1)
      return s;
    
    int st = 0, end = 0;
    int max_len = 1;
      
    for(int i=0; i<n-1; i++)
    {
      int l = i, r=i;
      while(l>=0 && r<n)
      {
        if(s[l]!=s[r])
          break;
        l--;
        r++;
      }
      int len = r-l-1;
      if(len > max_len){
        max_len = len;
        st = l+1;
        end = r-1;
      }
    }
    
    for(int i=0; i<n-1; i++)
    {
      int l=i, r=i+1;
      
      while(l>=0 && r<n)
      {
        if(s[l]!=s[r])
          break;
        l--;
        r++;
      }
      int len = r-l-1;
      if(len > max_len)
      {
        max_len = len;
        st = l+1;
        end = r-1;
      }
    }
    
    return s.substr(st, max_len);
    
}