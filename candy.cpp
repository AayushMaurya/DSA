// Candy

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

int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int> height(n, 1);
        
        for(int i=1; i<n; i++)
        {
            if(ratings[i] > ratings[i-1])
                height[i] = height[i-1]+1;
        }
        
        int ans=0;
        for(int i=n-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1])
                height[i] = max(height[i], height[i+1]+1);
            ans += height[i];
        }
        return ans+height[n-1];
    }