#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int CountDays(vector<int>& weights, int cap) {
        int days = 1;
        int load = 0;

        for(int i = 0; i < weights.size(); i++) {
            if(load + weights[i] > cap) {
                days++;
                load = weights[i];
            }
            else {
                load = load + weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = 0;
        int sum = 0;

        for(int i = 0; i < weights.size(); i++) {
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }

        int low = maxi;
        int high = sum;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int numberofDays = CountDays(weights, mid);
            if(numberofDays <= days) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};