// median of 2 sorted arrays of equal size 
// O(logn)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
ll max(ll x, ll y)
{
    return (x>y)?x:y;
}
ll min(ll x, ll y)
{
    return (x>y)?y:x;
}
void swap(ll *x, ll *y)
{
    ll temp = *x;
    *x = *y;
    *y = temp;
}


int median(int arr[], int n)
{
    if (n % 2 == 0)
        return (arr[n / 2] +
                arr[n / 2 - 1]) / 2;
    else
        return arr[n / 2];
}

int getMedian(int ar1[], int ar2[], int n)
{
    if(n<=0)
        return -1;
    if (n == 1)
        return (ar1[0] +
                ar2[0]) / 2;
    if (n == 2)
        return (max(ar1[0], ar2[0]) +
                min(ar1[1], ar2[1])) / 2;

    int m1 = median(ar1, n);
    int m2 = median(ar2, n);

    if (m1 == m2)
        return m1;

    else if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n / 2 - 1, ar2, n - n / 2 + 1);
        else 
            return getMedian(ar1 + n / 2, ar2, n - n / 2);
    }
    else if(m2 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar2 + n / 2 - 1, ar1, n - n / 2 + 1);
        else 
            return getMedian(ar2 + n / 2, ar1, n - n / 2);
    }
    return -1;
}

void solve()
{
    int n;
    cin>>n;
    int ar1[n], ar2[n];

    for(int i=0 ; i<n ; i++)
        cin>>ar1[i];

    for(int i=0 ; i<n ; i++)
        cin>>ar2[i];

    cout<<getMedian(ar1, ar2, n);

    return;
}

int main()
{
	solve();
	return 0;
}