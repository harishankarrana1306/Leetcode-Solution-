class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int net_gain = gain[0];
        int start = 0;

        for(int i = 0;i < gain.size();i++){
            start = start  + gain[i];

            if(net_gain < start){
                net_gain = start;
            }
        }
        if(net_gain<0){
            return 0;
        }
        return net_gain;   
    }
};