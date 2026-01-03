class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1000000007;
        long long a = 6 , b = 6;

        for(int i = 2; i <= n; i++){
            long long newA = (2 * a + 2 * b)%MOD;
            long long newB = (2 * a + 3 * b)%MOD;
            a = newA;
            b = newB;
        }
        return (a + b)%MOD;
    }
};