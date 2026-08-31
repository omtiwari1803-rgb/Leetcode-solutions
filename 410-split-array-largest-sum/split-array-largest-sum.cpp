#include<bits/stdc++.h>
class Solution {
public:
    int NumSubArr(vector<int>& nums, int k, int mid){
        int n= nums.size();
        int NumSubArr=1;
        long long SumOfElements=0;
        for(int i=0;i<n;i++){
            if(SumOfElements+nums[i] <= mid){
                SumOfElements += nums[i];
            }
            else{
                NumSubArr++;
                SumOfElements = nums[i];
            }
        }
        return NumSubArr;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low= *max_element(nums.begin(),nums.end());
        long long high= accumulate(nums.begin(),nums.end(),0);

        while(low<=high){
            int mid=(low+high)/2;
            int NumOfSubArr = NumSubArr(nums,k,mid);
            if(NumOfSubArr > k){
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }
        return low;
    }
};