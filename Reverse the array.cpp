// Recursive C++ program to reverse an array
#include <bits/stdc++.h>
using namespace std;

void rvereseArray(int arr[], int start, int end)
{
	if (start >= end)
	return;
	
	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
	
	rvereseArray(arr, start + 1, end - 1);
}	

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0 ; i<n ; i++)
		cin>>arr[i];
	rvereseArray(arr, 0, n-1);
	
	cout << "Reversed array is" << endl;
	
	for(int i=0 ; i<n ; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
