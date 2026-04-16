#include <memory_resource>
pmr::unsynchronized_pool_resource pool;
class Solution {
public:
    static vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        const int n=nums.size(), qz=queries.size();
        vector<int> ans(qz, -1);
        
        // Store the indices
        pmr::unordered_map<int, vector<int>> x2i(&pool);
        x2i.reserve(n);   
        for (int i=0; i<n; i++) 
            x2i[nums[i]].push_back(i);
    
        // Process each query
        for (int i=0; i<qz; i++) {
            const int q=queries[i], x=nums[q];
            auto& idx=x2i[x];
            const int sz=idx.size();

            if (sz==1) continue;

            // Find the position of index q 
            auto i0=lower_bound(idx.begin(), idx.end(), q)-idx.begin();

            int d=n-1, j0=idx[i0];  // Maximum distance

            // Check next index 
            if (i0+1!=sz) d=min(d, idx[i0+1]-j0);
            else d=min(d, n+idx[0]-j0);  // Wrap around to the first

            // Check previous index (circularly)
            if (i0!=0) d=min(d, j0-idx[i0-1]);
            else d=min(d, n+j0-idx.back());  // Wrap around to the last
            ans[i]=d;
        }
        return ans;
    }
};
