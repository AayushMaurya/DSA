#include<bits/stdc++.h>
using namespace std;
# define ll long long int

long double area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    long double out = (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))*(0.5);
    return out;
}

int main()
{
    int n;
    cin>>n;
    int x1, y1, x2, y2, x3, y3;
    int res = 0;
    for(int i=0 ; i<n ; i++)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        long double area1 = abs(area(x1, y1, x2, y2, x3, y3));
        //cout<<area1<<endl;
        long double area2 = abs(area(0, 0, x2, y2, x3, y3));
        //cout<<area2<<endl;
        long double area3 = abs(area(x1, y1, 0, 0, x3, y3));
        //cout<<area3<<endl;
        long double area4 = abs(area(x1, y1, x2, y2, 0, 0));
        //cout<<area4<<endl;
        if(abs(area1-area2-area3-area4) < 1e-9)
            res++;
    }
    cout<<res<<endl;
    return 0;
}
