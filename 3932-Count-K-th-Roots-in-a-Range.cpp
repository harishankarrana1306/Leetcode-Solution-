class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int count =0;
        
        if (k == 1) {
            return r - l + 1;
        }


       for(int i=0; ;i++){
            if(pow(i,k) >=l && pow(i,k) <= r ){
                count++;
            }
            if(pow(i,k)>r){
                break;
            }
           
        }
       return count;
    }
};