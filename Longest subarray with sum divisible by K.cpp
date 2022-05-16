// Longest subarray with sum divisible by K

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


int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        int ans=0;
        map<int, int> mp;
        mp[0]=-1;
        long long sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
            // cout<<sum%k<<" ";
            int check = sum%k;
            if(check<0) check+=k;
            if(mp[check])
            {
                int x=mp[check];
                if(x==n)    x=0;
                ans=max(ans, i-x);
            }
            else{
                int x=i;
                if(i==0)    x=n;
                mp[check] = x;
            }
        }
        return ans;
    }
int main(){
    
    int n;
    cin>>n;
vector<vector<int>> vec(n, vector<int>(n));
for(int i=0; i<n; i++)
    cin>>vec[i][0]>>vec[i][1];

cout<<solve(vec, n, n)<<endl;
    return 0;
}