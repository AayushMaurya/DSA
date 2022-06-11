// magnet array problem

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

double solve(int l, int r, double magnets[], int n)
    {
        double low = 1.0*l, high = 1.0*r;
        while(high-low>=0.000001){
            double fleft = 0.0, fright = 0.0;
            double m = (high+low)/2;
            for(int i=0; i<n; i++){
                if(i<=l)
                    fright+=1.0/(m-magnets[i]);
                else
                    fleft += (1.0)/(magnets[i]-m);
            }
            if(fleft < fright)
                low = m;
            else
                high = m;
        }
        return low;
    }
    
        void nullPoints(int n, double magnets[], double getAnswer[])
    {
        for(int i=0; i<n-1; i++)
        {
            getAnswer[i] = solve(magnets[i], magnets[i+1], magnets, n);
        }
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}