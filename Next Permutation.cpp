// Next Permutation

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

int binarySearch(int *arr, int start, int n, int num)
{
	for(int i=start ; i<n ; i++)
	{
		if(arr[i] > num)
			return i;
	}
	return n-1;
}

void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0 ; i<n ; i++)
		cin>>arr[i];

	int max = arr[n-1];
	if(n <= 1)
		return;
	int i;
	for(i=n-2 ; i>=0 ; i--)
	{
		if(max > arr[i])
		{
			sort(arr+i+1, arr+n);
			int j=i+1;
			while(j<n && arr[j] <= arr[i])
				j++;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			break;
		}
		else	max = arr[i];
	}

	if(i < 0)
		sort(arr, arr+n);

	for(int k=0 ; k<n ; k++)
		cout<<arr[k]<<" ";
	cout<<endl;

	return;
}

int main()
{
	solve();
	return 0;
}