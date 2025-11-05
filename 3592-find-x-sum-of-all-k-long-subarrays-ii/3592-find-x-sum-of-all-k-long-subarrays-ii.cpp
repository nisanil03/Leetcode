class Solution {
public:
    using int2 = pair<int,int>; // (freq, value)
    unordered_map<int,int> freq;
    set<int2, greater<int2>> top, rest;
    long long curr_sum=0;
    inline void insert_val(int v, int x) {
        int& f=freq[v];
        if (f>0) {
            const int2 fv={f, v};
            auto it=top.find(fv);
            if (it!=top.end()) {
                top.erase(it);
                curr_sum-=1LL*f*v;
            }
            else rest.erase(fv);
        }

        top.insert({++f,v});
        curr_sum+=1LL*f*v;

        // too many in top, move smallest one
        if (top.size()>x) {
            auto it=prev(top.end());
            curr_sum-=1LL*it->first*it->second;
            rest.insert(*it);
            top.erase(it);
        }
    }

    inline void erase_val(int v, int x) {
        int& f=freq[v];
        if (f==0) return;
        const int2 fv={f, v};
        auto it=top.find(fv);
        if (it!=top.end()){
            top.erase(it);
            curr_sum-=1LL*f*v;
        }
        else rest.erase(fv);

        if (--f==0) 
            freq.erase(v);
        else 
            rest.insert({f,v});
            
        // Move head of rest to top if possible
        if (top.size()<x && !rest.empty()) {
            auto it=rest.begin();
            curr_sum+=1LL*it->first*it->second;
            top.insert(*it);
            rest.erase(it);
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        const int n=nums.size(), sz=n-k+1;
        vector<long long> ans(sz);
    
        freq.reserve(n);
        
        // 1st window
        for (int i=0;i<k;i++) insert_val(nums[i], x);
        ans[0]=curr_sum;

        // slide window
        for (int l=1, r=k; r<n; l++, r++) {
            erase_val(nums[l-1], x);
            insert_val(nums[r], x);
            ans[l]=curr_sum;
        }
        return ans;
    }
};
static const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();