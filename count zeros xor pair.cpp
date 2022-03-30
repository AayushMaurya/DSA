// Count Zeros XOR pair

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

long long int calculate(int a[], int n)
{
    unordered_map<int, int> mp;
    
    for(int i=0; i<n; i++)
        mp[a[i]]++;
        
    long long res = 0;
    
    for(auto itr=mp.begin(); itr!=mp.end(); itr++)
    {
        res += ((itr->second)*(itr->second-1))/2;
    }
    return res;
}


int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<solve(arr, n)<<endl;
    return 0;
}