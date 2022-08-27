// Max sum of rectangle no larget than k
// TC = (m^2)*n(log(n))

#include <bits/stdc++.h>
using namespace std;


int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int ans = INT_MIN;
        
        for(int left = 0; left<matrix[0].size(); left++)
        {
            vector<int> arr(matrix.size(), 0);
            for(int right=left; right<matrix[0].size(); right++)
            {
                int csum = 0, max_sum = INT_MIN;
                set<int> cum_set;
                cum_set.insert(0);
                for(int i=0; i<matrix.size(); i++){
                    arr[i] += matrix[i][right];
                    
                    csum += arr[i];
                    
                    set<int>::iterator sit = cum_set.lower_bound(csum - k);
                    
                    if (sit != cum_set.end())
                        max_sum = max(max_sum, csum - *sit);
                    
                    cum_set.insert(csum);
                }
                ans = max(ans, max_sum);
            }
        }
        return ans;
    }