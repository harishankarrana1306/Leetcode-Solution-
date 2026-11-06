class Solution {
public:
    int reverse(int x) {
        
        int reverseno =0;
        while(x != 0){
            int remainder = x%10;
            x=x/10;

            if(reverseno > INT_MAX/10 || 
              (reverseno == INT_MAX/10 && remainder > 7)) {
                return 0;
            }

            if(reverseno < INT_MIN/10 || 
              (reverseno == INT_MIN/10 && remainder < -8)) {
                return 0;
            }


            reverseno =  ((reverseno*10)+ remainder);
        }
        return reverseno;
    }
};