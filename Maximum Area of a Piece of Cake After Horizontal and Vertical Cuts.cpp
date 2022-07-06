// Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

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

int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        int initial = 0;
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int ma = horizontalCuts[0];
        int ma2 = verticalCuts[0];
        
        for(int itr: horizontalCuts){
            ma = max(ma, itr-initial);
            initial = itr;
        }
        
        ma = max(ma, h-initial);
        
        for(auto itr: verticalCuts){
            ma2 = max(ma2, itr-initial);
            initial = itr;
        }
        
        ma2 = max(ma2, w-initial);
        
        return (int)((1LL*ma)%1000000007 * (1LL*ma2)%1000000007)%1000000007;
    }