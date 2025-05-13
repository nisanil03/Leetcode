class Solution {
public:
    const int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        int freq[26]={0};
        for(char c : s) freq[c - 'a']++;

        for(t; t>0; t--){
            long long f25=freq[25], f0=freq[0];
            for(int i = 25; i>= 2; i--){
                freq[i]=freq[i-1];
            }
            freq[0]=f25;
            f0+=f25;
            if(f0>=mod) f0-=mod;
            freq[1]=f0;
        }
        return reduce(freq , freq + 26 , 0LL)%mod;
    }
};