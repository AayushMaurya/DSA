// Check if it is possible to survive on Island

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

int minimumDays(int S, int N, int M){
        if(N<=M)
            return -1;
        
        if(S>6)
        {
            if(7*M<=N*6)
            {
                int rem = (S*M)/N;
                int div = (S*M)%N;
                if(div>0)
                    rem++;
                return rem;
            }
            else
                return -1;
        }
        else{
            int rem = (S*M)/N;
            int div = (S*M)%N;
            if(div>0)
                rem++;
            return rem;
        }
    }


int main(){
    int S,N,M;
    cin>>S>>N>>M;

    cout<<solve(S, N, M)<<endl;
    return 0;
}