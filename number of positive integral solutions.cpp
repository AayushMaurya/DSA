// Number of positive integral solutions
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

long nCr(int n, int r)
    {
        if(n<r) return 0;
        
        if(r==1)
            return n;
        if(r==0 || n==r)
            return 1;
            
        return (nCr(n-1, r-1)*n)/r;
    }

    long posIntSol(string s)
    {
        int count=0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '+')
                count++;
        }
        int i=s.size()-1;
        
        string temp = "";
        while(s[i]!='='){
            temp = s[i] + temp;
            i--;
        }
        
        int sum = stoi(temp);
        count++;
        // cout<<count<<" "<<sum<<endl;
        if(count == 1)
            return 1;
        
        long ans = nCr(sum-1, count-1);
        
        return ans;
    }