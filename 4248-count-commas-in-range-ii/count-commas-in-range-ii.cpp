class Solution {
public:
    long long countCommas(long long n) {
        long current = 1000;
        long resource = 0;
        while(current <= n){
            resource += n - current + 1;
            current *= 1000;
        }
        return resource;
    }
};