// find all pairs on integer array whose sum is equal to given number

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back


void solve()
{
	int n, k;
	cin>>n>>k;
	int arr[n];
	for(int i=0 ; i<n ; i++)
		cin>>arr[i];

	int count=0;
	map<int, int> m;

	for(int i=0 ; i<n ; i++)
		m[arr[i]]++;

	for(int i=0 ; i<n ; i++)
	{
		count += m[k-arr[i]];

		if(k-arr[i] == arr[i])
			count--;
	}
	cout<<count/2<<endl;
	return;
}

int main()
{
	solve();
	return 0;
}