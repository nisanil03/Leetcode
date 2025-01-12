class Solution {
public:
    bool canBeValid(string s, string locked) {
        const int n = s.size();
        if(n&1) return 0;
        int bMin = 0, bMax = 0;
        for(int i = 0 ; i < n ;i++){
            bool op = s[i] == '(' , wild = locked[i] == '0';
            bMin += (!op|wild)?-1:1;
            bMax += (op|wild)?1:-1;
            if(bMax<0)return 0;
            bMin = max(bMin ,0);
        }
        return bMin == 0;
    }
};