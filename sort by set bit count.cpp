// Sort by set bit count

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

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int ma=INT_MIN;
    map<int, std::vector<int>> mp;
    for(int i=0; i<n; i++)
    {
        int temp=arr[i], count=0;
        while(temp)
        {
            if(temp%2==1)
                count++;
            temp=temp/2;
        }
        ma=max(ma, count);
        mp[count].push_back(arr[i]);
    }
    int j=0;
    for(int i=ma; i>=0; i--)
    {
        if(!mp[i].empty())
        {
            for(auto itr=mp[i].begin(); itr!=mp[i].end(); itr++)
            {
                arr[j]=*itr;
                j++;
            }
        }
    }
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return;
}

int main(){
    solve();
    return 0;
}