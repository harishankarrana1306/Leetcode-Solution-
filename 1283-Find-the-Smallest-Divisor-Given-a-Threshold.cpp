class Solution {
public:


    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1; //smallest divisor is 1.
        int high = *max_element(nums.begin(),nums.end());  //if the divisor is 1 ;sum = sum of all arr[i]
        // for(int divisor=1 ;divisor <= high ;divisor++){    //upto which number can be used as divisor
        //     int sum = 0;

        //     for(int j=0; j<n; j++){
        //         sum += ceil((double)nums[j]/divisor);
        //     }                                                    //This method leaves with time limit exceed

        //     if(sum <= threshold){
        //         return divisor;
        //     }

        // }

        while(low <= high){
            int divisor = low +(high-low)/2;
            long long sum =0;
            for(int j=0; j<n; j++){
                sum += ceil((double)nums[j]/divisor);
            }

            if(sum<=threshold){
                high = divisor-1;
            }

            else{
            low = divisor + 1 ;
            }
        }
        return low;
    }
};