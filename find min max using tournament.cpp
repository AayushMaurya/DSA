// Find min max using tournament method
#include <bits/stdc++.h>
using namespace std;


struct Pair{
	int min;
	int max;
};

struct Pair getminmax(int arr[], int low, int high)
{
	struct Pair minmax, mml, mmr;
	if(high == low)
	{
		minmax.min = arr[low];
		minmax.max = arr[low];
	}

	else if(high == low+1)
	{
		if(arr[low] < arr[high])
		{
			minmax.min = arr[low];
			minmax.max = arr[high];
		}
		else
		{
			minmax.min = arr[high];
			minmax.max = arr[low];
		}
	}

	else{
		int mid = (high+low)/2;

		mml = getminmax(arr, low, mid);
		mmr = getminmax(arr, mid+1, high);

		if(mml.min < mmr.min)
			minmax.min = mml.min;
		else
			minmax.min = mmr.min;

		if(mml.max > mmr.max)
			minmax.max = mml.max;
		else
			minmax.max = mmr.max;
	}

	return minmax;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];

	for(int i=0 ; i<n ; i++)
		cin>>arr[i];

	struct Pair minmax = getminmax(arr, 0, n-1);

	cout<<"min = "<<minmax.min<<endl;
	cout<<"max = "<<minmax.max<<endl;

	return 0;
}