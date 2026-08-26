class Solution {
public:
    int MaxEle(vector<int>& piles){
        int maxi=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }

    long long TotalHourCount(vector<int>& piles, int hour){
        long long totalH = 0;
        int n= piles.size();
        for(int i=0;i<n;i++){
            totalH = totalH + ceil(double(piles[i])/double(hour));
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=MaxEle(piles);
        int ans = INT_MAX;
        while(low<=high){
            int mid= (low+high)/2;
            long long totalH = TotalHourCount(piles,mid);
            if(totalH <= h){
                ans = mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};