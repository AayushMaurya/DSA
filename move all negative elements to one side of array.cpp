//  move all the negatve elements of arrat to end of it in order

#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0 ; i<n ; i++)
		cin>>arr[i];
	
	int temp[n], j=0;

	for(int i=0 ; i<n ; i++)
	{
		if(arr[i] >= 0)
			temp[j++] = arr[i];
	}

	for(int i=0 ; i<n ; i++)
	{
		if(arr[i] < 0)
			temp[j++] = arr[i];
	}

	memcpy(arr, temp, sizeof(temp));
	
	return;
}

int main()
{
	solve();
	return 0;
}