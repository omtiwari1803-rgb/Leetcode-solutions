#include <bits/stdc++.h>
class Solution {
public:
    int SumofDivision(vector<int>& nums, int divisor){
        int n= nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + ceil(double(nums[i])/double(divisor));
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size() > threshold) return -1;
        
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int low=1, high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(SumofDivision(nums,mid) <= threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};