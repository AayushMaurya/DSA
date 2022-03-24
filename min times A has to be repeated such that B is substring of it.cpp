// Minimum times A has to be repeated such that B is a substring of it

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

int minRepeats(string A, string B) {
        
        vector<int> occu;
        for(int i=0; i<A.length(); i++)
        {
            if(B[0] == A[i])
                occu.push_back(i);
        }
        
        for(auto j:occu)
        {
            int res=1;
            int i;
            for(i=0; i<B.length(); i++)
            {
                if(j>=A.length()){
                    j=0;
                    res++;
                }
                if(A[j] == B[i])
                    j++;
                else
                    break;
            }
            if(i>=B.length())
                return res;
        }
        return -1;
    }

int main(){
    string A, B;
    cin>>A>>B;
    
    cout<<minRepeats(A, B)<<endl;
    return 0;
}