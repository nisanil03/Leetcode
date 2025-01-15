class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int set_bits = __builtin_popcount(num2);
        int res = 0;
        for(int i = 31; i>= 0 && set_bits;i--){
            if(num1 &(1<<i)){
            set_bits--;
            res += (1<<i);

            }
        }
        for(int i = 0; i <= 31 && set_bits;i++){
            if((num1 & (1<<i))==0){
            set_bits--;
            res +=(1<<i); 
            }
        }
        return res;
    }
};