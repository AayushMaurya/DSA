// Maximum Points You Can Obtain from Cards

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

int maxScore(vector<int>& arr, int k) {
        
        k = arr.size()-k;
        
        int ans = INT_MAX;
        int sum=0;
        int t_sum=0;
        for(int i=0; i<k; i++){
            sum += arr[i];
            t_sum += arr[i];
        }
        
        ans = min(ans, sum);
        
        for(int i=k; i<arr.size(); i++)
        {
            t_sum += arr[i];
            sum += arr[i];
            sum -= arr[i-k];
            
            ans = min(ans, sum);
        }
        return t_sum-ans;
    }