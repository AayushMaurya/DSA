// DFS of graph

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

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        stack<int> st;
        vector<bool> visited(V, false);
        
        st.push(0);
        while(!st.empty())
        {
            int temp = st.top();
            st.pop();
            if(visited[temp])   continue;
            ans.push_back(temp);
            visited[temp] = true;
            
            for(int i=adj[temp].size()-1; i>=0; i--)
                    st.push(adj[temp][i]);
        }
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}