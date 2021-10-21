// sort array of 0s, 1s and 2s with the help of map

#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0 ; i<n ; i++)
		cin>>arr[i];
	map<int, int> m;
	m[0] = 0;
	m[1] = 0;
	m[2] = 0;
	for(int i=0 ; i<n ; i++)
	{
		if(arr[i] == 0)
			m[0]++;
		else if(arr[i] == 1)
			m[1]++;
		else
			m[2]++;
	}
	while(m[0]--)
		cout<<0<<" ";
	while(m[1]--)
		cout<<1<<" ";
	while(m[2]--)
		cout<<2<<" ";
	
	return;
}

int main()
{
	solve();
	return 0;
}