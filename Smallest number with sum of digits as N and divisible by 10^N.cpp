// Smallest number with sum of digits as N and divisible by 10^N

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

string digitsNum(int N)
    {
        string res="";
        for(int i=0; i<N; i++)
            res = res+"0";
        while(N)
        {
            if(N>9)
               {
                   res="9"+res;
                   N=N-9;
               }
            else{
                char c = '0'+N;
                res = c+res;
                N=0;
            }
        }
        
        return res;
    }

int main(){
    int n;
    cin>>n;

    // int arr[n];
    // for(int i=0; i<n; i++)
    //     cin>>arr[i];

    cout<<digitsNum(n)<<endl;
    return 0;
}