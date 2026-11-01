class Solution {
public:

    int funct(vector<int>& weights, int capacity){
        int days =1;
        int load=0;
        for(int i=0;i<weights.size();i++){

            if(load +weights[i] > capacity){
                days = days+1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }




    int shipWithinDays(vector<int>& weights, int days) {
        int highest = *max_element(weights.begin(),weights.end());
        //first thing to be figure out is what could be the maximum capacity of a ship ? sum  = total arr[i]
        // 1. its must be >= high else it will be not able to ship each and every product  = high
        int sum = 0;
        for(int i = 0;i<weights.size();i++){
            sum += weights[i];
        }

        // for(int capacity = high; capacity <= sum; capacity++){
            
        //     int daysrequired = funct(weights, capacity);
        //         if(daysrequired <= days){
        //             return daysrequired;
        //         }
        // }
        // return -1;

        int low = highest;
        int high = sum;

        while(low <= high ){
            int mid = low + (high-low)/2;

            int gettingdays = funct(weights,mid);
            if(gettingdays <= days){
                    high = mid-1;
            }
            else{
                low  = mid+1;
            }
        }
        return low;

    }
};