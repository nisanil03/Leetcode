class Solution {
public:
   static int numWays(vector<string>& words, string& target) {
        const int mod = 1e9+7;
        const int m = target.size() , n = words[0].size();

        int freq[26][1000]={0};
        for(int i = 0; i < n ;i++){
            for(const auto& w : words)
            freq[w[i] - 'a'][i]++;
        }
        int dp[1001]={0};
        dp[0]=1;

        for(int i = 0; i < n; i++){
            for(int j = m; j >=1; j--){
                long long fc = freq[target[j-1]-'a'][i];
                dp[j]=(dp[j]+dp[j-1]*fc) % mod;
            }
        }
        return dp[m];
    }
};