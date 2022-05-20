#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse(int a[], int start, int end)
{
	while(start < end)
	{
		int temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}
}

void solve()
{
	int n;
	cin<<n;
	int a[n];
	for(int i=0 ; i<n ; i++)
		cin>>a[i];
	reverse(a, 0, sizeof(a)/sizeof(a[0]) - 1);

	for(int i=0 ; i<n ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void main() {
	int t;
	cin>>t;
	while(t--)
		solve();
}