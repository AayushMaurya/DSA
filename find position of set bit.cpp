// Find Position of set bit

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

int findPosition(int N) {
        int res=-1;
        int count=1;
        vector<int> bit;
        while(N)
        {
            bit.push_back(N%2);
            if(N%2==1){
                if(res!=-1)
                    return -1;
                res=count;
            }
            N=N/2;
            count++;
        }
        return res;
    }

int main(){
    int n;
    cin>>n;
    cout<<findPosition(n)<<endl;
    return 0;
}