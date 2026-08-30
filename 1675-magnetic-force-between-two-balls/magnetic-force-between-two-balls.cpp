class Solution {
public:
    bool canWePlace(vector<int>& position, int dist, int m){
        int cntBalls=1, last=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last >= dist){
                cntBalls++;
                last=position[i];
            }
        }
        if(cntBalls >= m){
            return true;
        }
        else{
            return false;
        }
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=1, high=position[n-1]-position[0];

        while(low<=high){
            //mid will contain the minimum distance to be maintained between the balls
            int mid=(low+high)/2;
            if(canWePlace(position,mid,m) == true){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};