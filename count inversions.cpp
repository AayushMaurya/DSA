// Count inversions in an array using merge sort

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back


ll merge(ll arr[], ll temp[], ll start, ll mid, ll end)
{
	ll inversions=0;
	ll i, j, k;

	i=start;	// for left part
	j=mid;		// for right part
	k=start;	// for temp array

	while(i<=mid-1 && j<=end)
	{
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else{
			temp[k++] = arr[j++];

			inversions += (mid-i);	// all the indexes after i will make pair with j
		}
	}

	while(i<=mid-1)
		temp[k++] = arr[i++];

	while(j<=end)
		temp[k++] = arr[j++];

	for(ll i=start ; i<=end ; i++)
		arr[i] = temp[i];

	return inversions;
}

ll mergeSort(ll arr[], ll temp[], ll start, ll end)
{
	ll inversions = 0;
	if(end <= start)
		return inversions;

	ll mid = (start+end)/2;

	// inversions of right part + left part
	inversions += mergeSort(arr, temp, start, mid);
	inversions += mergeSort(arr, temp, mid+1, end);

	// inversions on merging the two parts
	inversions += merge(arr, temp, start, mid+1, end);

	return inversions;
}

ll countInversion(ll arr[], ll n)
{
	ll temp[n];
	return mergeSort(arr, temp, 0, n-1);
}

int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0 ; i<n ; i++)
		cin>>arr[i];

	cout<<countInversion(arr, n)<<endl;
	return 0;
}