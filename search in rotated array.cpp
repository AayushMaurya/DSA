// Search in rotated array

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

int search(int A[], int l, int h, int key){
        while(l<=h)
        {
            int mid = (l + h)/2;
            if(A[mid] == key)
                return mid;
            else if(A[mid] >= A[l])
            {
                if(key>=A[l] && key<=A[mid])
                    h=mid-1;
                else
                    l=mid+1;
            }
            else
            {
                if(key>=A[mid] && key<=A[h])
                    l=mid+1;
                else
                    h=mid-1;
            }
        }
        return -1;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}