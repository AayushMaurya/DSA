// Partition array to K subsets

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

bool solve(int index, int a[], int n, vector<int>& sum, int k)
    {
        if(index==n)
        {
            for(int i=1; i<k; i++)
            {
                if(sum[i]!=sum[i-1])
                    return false;
            }
            return true;
        }
        unordered_map<int, int> mp;
        for(int i=0; i<k; i++)
        {
            if(sum[i]-a[index]>=0 && !mp[sum[i]])
            {
                sum[i] -= a[index];
                if(solve(index+1, a, n, sum, k))
                    return true;
                sum[i] += a[index];
                mp[sum[i]]++;
            }
        }
        
        return false;
    }
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int s=accumulate(a, a+n, 0);
        if(s%k!=0)
            return false;
        s = s/k;
        
        vector<int> sum(k, s);
        
        return solve(0, a, n, sum, k);
    }