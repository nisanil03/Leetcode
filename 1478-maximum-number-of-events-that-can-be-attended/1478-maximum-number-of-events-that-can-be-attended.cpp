class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int n = events.size();
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq; 
        int maxEvents=0;
        int i=0;

        for (int day=1; i<n || !pq.empty(); day++) {
            if (pq.empty()) day=events[i][0];

            while (i<n && events[i][0]<=day) {
                pq.push(events[i][1]);
                i++;
            }

            while (!pq.empty() && pq.top() < day) 
                pq.pop();
            

            if (!pq.empty()) {
                pq.pop();
                maxEvents++;
            }
        }

        return maxEvents;
    }
};