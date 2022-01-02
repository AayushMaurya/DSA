// Fractional Knapsack

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

struct Item{
    int value;
    int weight;
};

double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, int>> v;
        for(int i=0 ; i<n ; i++)
        {
            double x = (arr[i].value*1.0)/(arr[i].weight*1.0);
            v.push_back({x, i});
        }
        
        sort(v.rbegin(), v.rend());
        int s=0;
        double res=0;
        
        for(int i=0 ; i<v.size() ; i++)
        {
            if(s+arr[v[i].second].weight < W)
            {
                s += arr[v[i].second].weight;
                res += arr[v[i].second].value;
            }
            else
            {
                double x = (W-s)*1.0;
                res += (x*v[i].first);
                break;
            }
        }
        
        return res;
    }

void solve(){
    int n, w;
    cin>>n>>w;

    Item arr[n];

    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i].value>>arr[i].weight;
    }

    cout<<fractionalKnapsack(w, arr, n);

    return;
}

int main(){
    solve();
    return 0;
}