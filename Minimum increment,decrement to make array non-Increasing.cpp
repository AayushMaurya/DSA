// Minimum increment/decrement to make array non-Increasing

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

int minOperations(int *a,int n)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(!pq.empty() && pq.top() < a[i]){
                ans += a[i] - pq.top();
                pq.push(a[i]);
                pq.pop();
            }
            pq.push(a[i]);
        }
        return ans;
    }

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<minOperations(arr, n)<<endl;
    return 0;
}