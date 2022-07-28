// Find First and Last Position of Element in Sorted Array

#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        if(n==0)
            return {-1, -1};
        
        int a=-1, b=-1;
        
        int left = 0, right = n-1;
        
        while(left<=right)
        {
            int mid = (left + right)/2;
            
            if(nums[mid] <= target){
                a = mid;
                left = mid + 1;
            }
            else 
                right = mid - 1;
        }
        left = 0;
        right = n-1;
        while(left<=right)
        {
            int mid = (left + right)/2;
            
            if(nums[mid] < target){
                left = mid + 1;
            }
            else {
                right = mid - 1;
                b = mid;
            }
        }
        if(b>a || a==-1 || b==-1)
            return {-1, -1};
        return {b, a};
        
    }