// Brain Game

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

int primeFactors(int n)
    {
        int ans=0;
        int num = n;
        
        for(int i=2; i<=num/2; i++)
        {
            while(n%i==0)
            {
                ans++;
                n /= i;
            }
        }
        return ans;
    }
    
    bool isPrime(int n)
    {
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    
    bool brainGame(vector<int>nums) {
        int ans=0;
        
        for(auto itr: nums)
        {
            if(!isPrime(itr))
                ans = ans ^ (primeFactors(itr)-1);
        }
        
        return ans!=0;
    }