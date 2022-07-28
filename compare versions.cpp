// compare versions

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
# define pii pair<int, int>
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

int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        
        int number1=0, number2=0;
        
        int i=0, j=0;
        
        while(i<n1 || j<n2)
        {
            while(i<n1 && version1[i]!='.')
            {
                number1 = number1*10 + (version1[i]-'0');
                i++;
            }
            
            while(j<n2 && version2[j]!='.')
            {
                number2 = number2*10 + (version2[j]-'0');
                j++;
            }
            
            if(number1 < number2)
                return -1;
            if(number2 < number1)
                return 1;
            
            number1=0;
            number2=0;
            
            i++;
            j++;
        }
        
        return 0;
    }