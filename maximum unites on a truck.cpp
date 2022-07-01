// Maximum unites on a truck

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

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int n = boxTypes.size();
        vector<vector<int>> box(n, vector<int>(2));
        
        for(int i=0; i<n; i++)
        {
            box[i][0] = boxTypes[i][1];
            box[i][1] = boxTypes[i][0];
        }
        
        sort(box.rbegin(), box.rend());
        
        int i=0, ans=0;
        while(truckSize && i<n)
        {
            if(truckSize > box[i][1])
            {
                ans += box[i][1]*box[i][0];
                truckSize -= box[i][1];
                i++;
            }
            else
            {
                ans += truckSize * box[i][0];
                truckSize = 0;
            }
        }
        return ans;
    }