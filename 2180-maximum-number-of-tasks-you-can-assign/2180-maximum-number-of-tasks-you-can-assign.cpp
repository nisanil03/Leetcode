class Solution {
public:
    int n, m, strength;
    bool doable(vector<int>& tasks, vector<int>& workers, int k, int pills){
        deque<int> q; 
        int t_idx = 0;
        for (int i = m-k; i<m; i++){
            int W = workers[i];
            for(; t_idx < k && tasks[t_idx] <= W+strength; t_idx++)
                q.push_back(tasks[t_idx]);
            
            if(q.empty()) return 0;
            if(q.front()<=W) q.pop_front(); 
            else{
                if(pills==0) return 0;
                pills--;
                q.pop_back(); 
            }
        }
        return 1;

    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        n = tasks.size(), m = workers.size();
        this->strength = strength;
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end()); 
        int l = 0, r = min(n, m); 
        while (l<r) {
            int mid=(l+r+1)/2;
            if (doable(tasks, workers, mid, pills))
                l=mid;
            else
                r=mid-1;
        }
        return l;
    }
};