// K divisible elements subarray

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

int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> ans;
        
        for(int i=0; i<nums.size(); i++)
        {
            int count=0;
            vector<int> res;
            for(int j=i; j<nums.size(); j++)
            {
                if(nums[j]%p==0)
                    count++;
                if(count>k)    break;
                // cout<<i<< " "<<j<<endl;
                res.push_back(nums[j]);
                ans.insert(res);
            }
        }
        
        return ans.size();
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}