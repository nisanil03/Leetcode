class Solution {
public:
    char findKthBit(int n, int k) {
        if(k == 1) return '0';
        int sz = 32- __builtin_clz(k);
        int k0=(1<<sz)-k;
        if(k0==k) return '1';

        return (findKthBit(n , k0)=='0')?'1':'0';
    }
};