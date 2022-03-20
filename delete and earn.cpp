// Delete and Earn

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

int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for(int i=0; i<n; i++)
            mp[nums[i]]++;
        int k = mp.size();
        int a[k], b[k];
        int j=0;
        int prev=0;
        for(auto i=mp.begin(); i!=mp.end(); i++)
        {
            if(j==0)
            {
                a[j] = i->first * i->second;
                b[j] = 0;
                j++;
            }
            else if(i->first - prev  == 1){
                a[j] = i->first * i->second + b[j-1];
                b[j] = max(a[j-1], b[j-1]);
                j++;
            }
            else{
                a[j] = i->first * i->second + max(b[j-1], a[j-1]);
                b[j] = max(a[j-1], b[j-1]);
                j++;
            }
            prev = i->first;
        }
        return max(a[k-1], b[k-1]);
    }

int main(){
    

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<deleteAndEarn(v)<<endl;
    return 0;
}