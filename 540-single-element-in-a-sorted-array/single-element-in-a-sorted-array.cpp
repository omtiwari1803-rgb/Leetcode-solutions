class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
        //if array of only one element
        if(n==1) return nums[0];

        //if 1st element is the unique one
        if(nums[0]!=nums[1]) return nums[0];

        //if last element is the unique one
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        // Initialize binary search bounds (exclude first and last index)
        int low=1, high=n-2;

        while(low<=high){
            int mid=(low+high)/2;
            
            //if middle element is the unique one 
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }

            //if mid is in the left of the single element (even,odd)
            if(((mid%2)==1 && nums[mid]==nums[mid-1] ) || (mid%2 == 0 && nums[mid] == nums[mid+1])){
                low=mid+1;
            }

            //if mid is in the right of the single element (odd,even)
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};