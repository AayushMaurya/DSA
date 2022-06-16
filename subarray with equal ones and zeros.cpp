// subarrays with equal 1's and 0's

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

long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        map<int, int> mp;
        int sum = 0;
        mp[sum]++;
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] == 1)
                sum++;
            else
                sum--;
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}