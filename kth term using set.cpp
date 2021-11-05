// find kth term using set
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin>>n>>k;
	int arr[n];

	for(int i=0 ; i<n ; i++)
	{
		cin>>arr[i];
	}

	set<int> s(arr, arr+n);

	auto itr = s.begin();
	advance(itr, k-1);
	cout<<*itr<<endl;
	return 0;
}