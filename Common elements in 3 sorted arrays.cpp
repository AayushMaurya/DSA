//find common elements in 3 sorted arrays

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back


void solve()
{
	int n1, n2, n3;
	cin>>n1>>n2>>n3;
	int A[n1], B[n2], C[n3];

	for(int i=0 ; i<n ; i++)
		cin>>A[i];
	for(int i=0 ; i<n ; i++)
		cin>>B[i];
	for(int i=0 ; i<n ; i++)
		cin>>C[i];

	int i=0, j=0, k=0;
        vector<int> v;
        while(i<n1 && j<n2 && k<n3)
            {
                if(A[i]<B[j] && A[i]<C[k])
                    i++;
                else if(B[j]<A[i] && B[j]<C[k])
                    j++;
                else if(C[k]<A[i] && C[k]<B[j])
                    k++;
                else if(A[i]==B[j] && A[i]<C[k])
                    i++;
                else if(A[i]==C[k] && A[i]<B[j])
                    i++;
                else if(B[j]==C[k] && B[j]<A[i])
                    j++;
                else if(A[i]==B[j] && A[i]==C[k])
                {
                    if(v.size() == 0)
                        v.push_back(A[i]);
                    else
                    {
                        if(*(v.end()-1) != A[i])
                            v.push_back(A[i]);
                    }
                    i++;
                    j++;
                    k++;
                }
            }
    for(auto it=v.begin() ; it!=v.end() ; it++)
    	cout<<*it<<" "<<endl;
    return;        
}

int main()
{
	solve();
	return 0;
}