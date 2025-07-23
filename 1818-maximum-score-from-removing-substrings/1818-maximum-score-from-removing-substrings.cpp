class Solution {
public:
    int maximumGain(string s, int x, int y) {
     int acount = 0;
     int bcount = 0;
     int lesser = min(x,y);
     int result = 0;

     for(char c : s){
        if(c > 'b'){
            result += min(acount , bcount) * lesser;
            acount = 0;
            bcount = 0;
        }
        else if (c == 'a'){
            if(x < y && bcount > 0){
                bcount--;
                result += y;
            }
            else{
                acount++;
            }
        }    
            else{
                if(x > y && acount > 0){
                    acount--;
                    result += x;
                }
                else{
                    bcount++;
                }
            }
        }
        result += min(acount , bcount) * lesser;
        return result;

    }   
    
};