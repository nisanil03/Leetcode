class Solution {
public:
    int minSubarray(vector<int>& a, int p) {
        int n = a.size();
        long long ts = 0;
        for (int x : a) {
            ts += x;
        }
        
        int r = ts % p;
        if (r == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;
        int crr = 0;
        int ml = n;
        
        for (int i = 0; i < n; ++i) {
            crr = (crr + a[i]) % p;
            int t = (crr - r + p) % p;
            
            if (mp.find(t) != mp.end()) {
                ml = min(ml, i - mp[t]);
            }
            
            mp[crr] = i;
        }
        
        return ml == n ? -1 : ml;
    }
};