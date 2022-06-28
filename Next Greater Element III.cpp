//  Next Greater Element III

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

int nextGreaterElement(int n) {
        string s = to_string(n);
        
        if(s.size() == 1)
            return -1;
        
        int i=s.size()-2;
        
        while(i>=0 && s[i] >= s[i+1])
            i--;
        
        if(i==-1)
            return -1;
        
        reverse(s.begin()+i+1, s.end());
        
        for(int j=i+1; j<s.size(); j++)
        {
            if(s[j] > s[i])
            {
                swap(s[j], s[i]);
                break;
            }
        }
        cout<<s<<endl;
        long ans = stol(s);
    
        if(ans > INT_MAX || ans==n)
                return -1;
        
        return ans;
    }