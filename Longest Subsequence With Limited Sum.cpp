// Longest Subsequence With Limited Sum

#include <bits/stdc++.h>
using namespace std;

vvector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i++)
            nums[i] += nums[i-1];
        
        vector<int> res;

        for(int i=0; i<queries.size(); i++)
        {
            int count = 0;

            while(count<nums.size() && nums[count] <= queries[i])
                count++;

            res.push_back(count);
        }

        return res;
    }