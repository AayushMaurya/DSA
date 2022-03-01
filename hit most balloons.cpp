// Hit Most balloons

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
// ll max(ll x, ll y)
// {
//     return (x>y)?x:y;
// }
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

int mostBalloons(int N, pair<int, int> arr[]) {
        
        int count=0;
        int ans=INT_MIN;
        for(int i=0; i<N; i++)
        {
            map<double, int> mp;
            count=0;
            pair<int, int> p=arr[i];
            for(int j=0; j<N; j++)
            {
                pair<int, int> q=arr[j];
                if(p==q)
                {
                    count++;
                    continue;
                }
                else{
                    double slope=(q.second-p.second)/((q.first-p.first)*1.0);
                    mp[slope]++;
                }
            }
            for(auto it=mp.begin(); it!=mp.end(); it++)
                ans=max(ans, it->second+count);
        }
        return ans;