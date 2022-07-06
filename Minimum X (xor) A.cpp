// Minimum X (xor) A

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

int minVal(int a, int b) {
        int a_bit[32] = {0};
        int b_bit[32] = {0};
        
        int tempa=a;
        int tempb=b;
        int counta=0;
        int countb=0;
        
        for(int i=31; i>=0; i--)
        {
            a_bit[i] = tempa%2;
            if(a_bit[i] == 1)
                counta++;
                
            b_bit[i] = tempb%2;
            if(b_bit[i] == 1)
                countb++;
            
            tempa /= 2;
            tempb /= 2;
        }
        if(counta==countb)
            return a;
            
        if(counta > countb)
        {
            int n = counta-countb;
            
            int i=31;
            while(n)
            {
                if(a_bit[i]==1)
                {
                    a_bit[i]=0;
                    n--;
                }
                i--;
            }
        }
        
        if(countb > counta)
        {
            int n = countb-counta;
            
            int i=31;
            while(n)
            {
                if(a_bit[i] == 0)
                {
                    a_bit[i]=1;
                    n--;
                }
                i--;
            }
        }
        
        int ans=0;
        
        for(int i=0; i<32; i++)
        {
            ans = ans*2 + a_bit[i];
        }
        
        return ans;
    }