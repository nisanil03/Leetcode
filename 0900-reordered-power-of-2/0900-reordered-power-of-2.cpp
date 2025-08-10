class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto CountDigits = [](int x){
            string s = to_string(x);
            sort(s.begin(), s.end());
            return s;
        };
        string target = CountDigits(n);
        for(int i = 0; i < 31; i++){
            if(CountDigits(1 << i) == target) return true;
        }
        return false;
    }
};