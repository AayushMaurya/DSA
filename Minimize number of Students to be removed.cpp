// Minimize number of Students to be removed

#include <bits/stdc++.h>
using namespace std;

int removeStudents(int a[], int n) {
	vector<int> arr;
	arr.push_back(a[0]);

	for(int i=1; i<n; i++)
	{
		if(a[i] > arr.back())
			arr.push_back(a[i]);
		else{
			auto index = lower_bound(arr.begin(), arr.end(), a[i]);
			*index = a[i];
		}
	}

	return n-arr.size();
}