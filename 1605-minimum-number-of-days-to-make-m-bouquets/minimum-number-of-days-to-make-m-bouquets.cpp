class Solution {
public:
    int FindMin(vector<int>& bloomDay){
        int n= bloomDay.size();
        int mini= INT_MAX;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<mini){
                mini = bloomDay[i];
            }
        }
        return mini;
    }

    int FindMax(vector<int>& bloomDay){
        int n= bloomDay.size();
        int maxi= INT_MIN;
        for(int i=0;i<n;i++){
            if(bloomDay[i]>maxi){
                maxi = bloomDay[i];
            }
        }
        return maxi;
    }

    int possible(vector<int>& bloomDay, int mid, int m, int k){
        int n= bloomDay.size();
        int cnt=0;
        int noofB=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{
                noofB = noofB + (cnt/k);
                cnt=0;
            }
        }
        noofB = noofB + (cnt/k);

        if(noofB>=m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n= bloomDay.size();
        long long val = m * 1LL * k * 1LL;
        if(val > n){
            return -1;
        }
        
        int low=FindMin(bloomDay), high=FindMax(bloomDay);
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k) == true){
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return low;
    }
};