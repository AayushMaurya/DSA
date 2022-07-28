//  first missing positive number 

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

int firstMissingPositive(vector<int>& nums)
{
    int n=nums.size();
    int i=0;

    while(i<n)
    {
        if(nums[i]==i+1 || nums[i]<=0 || nums[i]>n)
            i++;
        else if(nums[nums[i]-1]!=nums[i])
            swap(nums[nums[i]-1], nums[i]);
        else
            i++;
    }

    i=0;
    for(i=0; i<n; i++)
    {
        if(nums[i]!=i+1)
            break;
    }

    return i+1;
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<firstMissingPositive(arr);

    return 0;
}