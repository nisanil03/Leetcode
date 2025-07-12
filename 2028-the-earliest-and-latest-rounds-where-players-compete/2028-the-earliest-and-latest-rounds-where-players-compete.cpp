class Solution {
public:
    vector<int> earliestAndLatest(int n, int first, int second) {
        if (first + second == n + 1) return {1, 1};
        if (first + second > n + 1) tie(first, second) = make_tuple(n+1-second, n+1-first);
        
        int ans_earliest = 1, ans_latest = min(32 - __builtin_clz(n-1), n+1-second);
        if (first + second==n){
            if (first % 2 == 0) ans_earliest = first+2 < second? 2: 1 + __builtin_ctz(first);
        }
        else if (first+1 == second){
            ans_earliest = 32 - __builtin_clz((n-1) / (first+second-1));
            ans_earliest += __builtin_ctz((n-1)>>ans_earliest);
        }
        else if (first+second <= (n+1)/2) ans_earliest = 32 - __builtin_clz((n-1) / (first+second-1));
        return {ans_earliest+1, ans_latest};
    }
};