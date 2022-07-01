// Left most and right most index

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

pair<long,long> indexes(vector<long long> v, long long x)
    {
        long st=-1, en=-1;
        
        int flag=1;
        
        for(int i=0; i<v.size(); i++)
        {
            if(v[i] == x)
            {
                if(flag==1)
                {
                    flag=0;
                    st=i;
                }
                else
                    en=i;
            }
        }
        
        if(st==-1)
            return {-1, -1};
        if(en == -1)
            return {st, st};
            
        return {st, en};
        
        
    }