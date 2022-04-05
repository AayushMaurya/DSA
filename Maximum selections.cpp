// Maximum selections

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

int max_non_overlapping( vector< vector<int> >& ranges )
    {
        vector<pair<int, int>> p;
        int n = ranges.size();
        for(int i=0; i<n; i++)
            p.push_back({ranges[i][1], ranges[i][0]});
            
        sort(p.begin(), p.end());
        
        int res = 1;
        int end = p[0].first;
        for(int i=1; i<n; i++)
        {
            if(p[i].second >= end)
            {
                res++;
                end = p[i].first;
            }
        }
        return res;
    }


int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<max_non_overlapping(arr)<<endl;
    return 0;
}