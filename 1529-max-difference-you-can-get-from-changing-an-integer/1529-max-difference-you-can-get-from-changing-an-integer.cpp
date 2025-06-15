class Solution {
public:
  int n;
  vector<int> toDigit(int num){
    vector<int> ans(n);
    for(int x = num , i = n -1 ; x > 0; x /= 10 , i--){
        ans[i] = x % 10;
    }
    return ans;
  }
    int maxDiff(int num) {
        n = 1 + log10(num);
        vector<int> digit = toDigit(num);

        int a = -1;
        for(int i = 0 ; i < n && a == -1; i++){
            if(digit[i] != 9)
             a = digit[i];
        }
        int x = 0;
        for(int i = 0; i < n ; i++){
            if(digit[i] == a)
              x = 10 * x + 9;
            else
              x = 10 * x + digit[i];  
        }
        int b = -1 , y = 0;
        if(digit[0] != 1){
            b = digit[0];
            for(int i = 0; i < n; i++){
                if(digit[i] == b)
                y = 10 * y + 1;
                else
                  y = 10 * y + digit[i];
            }
        }
        else{
            for(int i = 1 ; i < n && b == -1 ;i++){
                if(digit[i] != 0 && digit[i] != 1){
                    b = digit[i];
                }
            }
            for(int i = 0 ; i < n ; i++){
                if(i == 0)
                   y = 10 * y + digit[i];
                else if (digit[i] == b)
                   y = 10 * y + 0;
                else
                  y = 10 * y + digit[i];      
            }
        }
        return x - y;
    }
};