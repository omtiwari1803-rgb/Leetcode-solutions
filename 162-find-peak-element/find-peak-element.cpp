class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();

        //if array is of one element
        if(n==1) return 0;

        //if 1st element is peak
        if(nums[0]>nums[1]) return 0;

        //if last element is peak
        if(nums[n-1]>nums[n-2]) return n-1;

        int low=1,high=n-2;
        while(low<=high){
            int mid= (low+high)/2;

            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }

            //peak on the left side of the array
            else if(nums[mid]>nums[mid+1]){
                high=mid-1;
            }

            //peak on the right side of the array
            else if(nums[mid]>nums[mid-1]){
                low=mid+1;
            }
            
            else{
                low=mid+1;
            }
        }
        return -1;
    }
};