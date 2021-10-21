// find min max element of an array using compare in pairs mathod
#include<bits/stdc++.h>
using namespace std;

pair<int, int> getminmax(int arr[], int n)
{
	int min, max, i=0;
	if(n%2 == 1)
	{
		min = arr[0];
		max = arr[0];
		i=1;
	}

	else
	{
		if(arr[0] > arr[1])
		{
			min = arr[0];
			max = arr[1];
		}
		else
		{
			min = arr[1];
			max = arr[0];
		}
		i=2;
	}

	while(i < n-1)
	{
		if(arr[i] > arr[i+1])
		{
			if(arr[i] > max)
				max = arr[i];
			if(arr[i+1] < min)
				min = arr[i+1];
		}
		else{
			if(arr[i+1] > max)
				max = arr[i+1];
			if(arr[i] < min)
				min = arr[i];
		}

		i = i+2;
	}

	pair<int, int> minmax;
	minmax.first = min;
	minmax.second =max;

	return minmax;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	pair<int, int> minmax = getminmax(arr, n);

	cout<<"min = "<<minmax.first<<endl;
	cout<<"mac = "<<minmax.second<<endl;

}