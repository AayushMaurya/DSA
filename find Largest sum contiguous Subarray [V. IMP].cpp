// Largest sum contiguous sub array by kadane's algorithm

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0 ; i<n ; i++)
		cin>>arr[i];

	ll maxsum=arr[0], currsum=0;
	for(int i=0 ; i<n ; i++){
		currsum+=arr[i];

		if(currsum > maxsum)
			maxsum = currsum;

		if(currsum < 0)
			currsum = 0;
	}

	cout<<maxsum<<endl;
}

int main()
{
	solve();
	return 0;
}