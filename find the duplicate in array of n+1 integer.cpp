// find duplicate in array of n+1 integer

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
	int size;
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++)
		cin>>arr[i];

	int index=size-1;
	while(arr[index]!=0){
		int temp=arr[index];
		arr[index]=0;
		index=temp-1;
	}
	cout<<index+1<<endl;
}

int main()
{
	solve();
	return 0;
}