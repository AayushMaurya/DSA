// implement atoi

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

int atoi(string str) {
        int ans=0;
        int flag=0;
        
        for(int i=0; i<str.size(); i++)
        {
            if(str[i] == '-' && i==0){
                flag=1;
                continue;
            }
            if(str[i] > '9' || str[i] < '0')
                return -1;
            int x = str[i]-'0';
            
            ans = ans*10 + x;
        }
        
        if(flag==1)
            ans = ans*-1;
        
        return ans;
    }