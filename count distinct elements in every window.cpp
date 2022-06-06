// Count distinct elements in every window

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

vector <int> countDistinct (int A[], int n, int k)
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        int count=0;
        for(int i=0; i<k; i++)
        {
            if(mp[A[i]]==0)
                count++;
            mp[A[i]]++;
        }
        ans.push_back(count);
        
        int l=0, r=k;
        
        while(r<n)
        {
            // cout<<mp[r]<<" "<<mp[l]<<endl;
            if(mp[A[r]]==0)
                count++;
                
            mp[A[r]]++;
            
            if(mp[A[l]]==1)
                count--;
                
            mp[A[l]]--;
                
            ans.push_back(count);
            l++;
            r++;
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