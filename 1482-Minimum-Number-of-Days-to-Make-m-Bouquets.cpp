class Solution {
public:


    bool possible(vector<int>& bloomDay, int day, int m, int k){
            int count = 0;
            int numberofbouquets = 0;
            for(int i =0;i<bloomDay.size();i++){
                if(bloomDay[i] <= day){
                    count++;
                }
                else{
                    numberofbouquets += (count/k);
                    count = 0;
                }
            }

            numberofbouquets += (count)/k; 

            if(numberofbouquets >= m){
                return true;
            }
            else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        if(1LL*m*k > bloomDay.size()){
            return -1;
        }

        // for(int day = min ; day<= max;day++){

        //     if(possible(bloomDay,day,m,k) == true){
        //         return day;
        //     }
        // }
        // return -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {
                high = mid-1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    
};