// Hungry Pizza Lovers 

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

vector<int> permute(vector<vector<int>> &arr, int n)
{
    
    vector<int> res(n);
    vector<pair<int, int>> pr;
    for(int i=0; i<n; i++)
    {
        pr.push_back({(arr[i][0]+arr[i][1]), i});
    }
    sort(pr.begin(), pr.end());
    
    for(int i=0; i<n; i++)
        res[i] = pr[i].second+1;
    return res;
}


int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<permute(arr, n)<<endl;
    return 0;
}