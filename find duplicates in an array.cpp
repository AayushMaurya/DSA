// find duplicates in an array

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

vector<int> duplicates(int arr[], int n) {
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++)
        {
            mp[arr[i]]++;
        }
        
        vector<int> ans;
        
        for(auto itr: mp)
        {
            if(itr.second > 1)
                ans.push_back(itr.first);
        }
        if(ans.size() <=0)
            ans.push_back(-1);
        sort(ans.begin(), ans.end());
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}