class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int64_t> gaps(n+1);
        gaps[0] = startTime[0];
        for (int i = 1; i < n; ++i) gaps[i] = int64_t(startTime[i]) - endTime[i-1];
        gaps[n] = int64_t(eventTime) - endTime[n-1];
        int64_t v1=0,v2=0,v3=0; int c1=0,c2=0,c3=0;
        for (int i = 0; i <= n; ++i) {
            int64_t g = gaps[i];
            if      (g>v1) { v3=v2; c3=c2; v2=v1; c2=c1; v1=g; c1=1; }
            else if (g==v1) c1++;
            else if (g>v2)  { v3=v2; c3=c2; v2=g; c2=1; }
            else if (g==v2) c2++;
            else if (g>v3)  { v3=g; c3=1; }
            else if (g==v3) c3++;
        }
        int64_t res = v1;
        for (int i = 0; i < n; ++i) {
            int64_t a = gaps[i], b = gaps[i+1], d = int64_t(endTime[i]) - startTime[i];
            int64_t m = a + d + b;
            int cnt1 = (a==v1) + (b==v1);
            int64_t best = cnt1 < c1 ? v1 : (((a==v2)+(b==v2)) < c2 ? v2 : v3);
            int64_t cand = best>=d ? (m>best?m:best) : (m-d>best?m-d:best);
            if (cand>res) res = cand;
        }
        return int(res);
    }
};