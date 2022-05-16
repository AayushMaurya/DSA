// K-th element of two sorted Arrays

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

int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int a=0, b=0;
        int count=0;
        while(a<n && b<m)
        {
            if(arr1[a] < arr2[b]){
                a++;
                count++;
                if(count==k)
                    return arr1[a-1];
            }
            else{
                b++;
                count++;
                if(count==k)
                    return arr2[b-1];
            }
        }
        while(a<n)
        {
            a++;
            count++;
            if(count==k)
                    return arr1[a-1];
        }
        while(b<m)
        {
            b++;
            count++;
                if(count==k)
                    return arr2[b-1];
        }
        return -1;
    }


int main(){
    
solve();
    return 0;
}