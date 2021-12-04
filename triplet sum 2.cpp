// find the triplet that sum to a given value
// using set

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


bool solve()
{
    int n, sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0 ; i<n ; i++)    cin>>arr[i];

	for(int i=0 ; i<n ; i++)
    {
        unordered_set<int> s;
        int curr_sum = sum-arr[i];

        for(int j=i+1 ; j<n ; j++)
        {
            if(s.find(curr_sum-arr[j]) != s.end())
                return true;
        s.insert(arr[j]);
        }
    }

    return false;
}

int main()
{
	cout<<solve();
	return 0;
}