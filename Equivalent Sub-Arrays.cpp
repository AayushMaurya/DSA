// Equivalent Sub-Arrays 

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

int countDistinctSubarray(int arr[], int n)
    {
        map<int, int> hash;
        for(int i=0; i<n; i++)
        {
            hash[arr[i]]=1;
        }
        
        map<int, int> pash;
        map<int, int> count;
        
        int st=0, en=0;
        int ans=0;
        for(en=0; en<n; en++)
        {
            pash[arr[en]] = 1;
            count[arr[en]]++;
            
            while(hash == pash)
            {
                ans += n-en;
                count[arr[st]]--;
                if(count[arr[st]]==0)
                    pash[arr[st]] = 0;
                st++;
            }
        }
        while(hash==pash)
        {
            ans ++;
            pash[arr[st]] = 0;
            st++;
        }
        return ans;
    }