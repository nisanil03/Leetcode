class Solution 
{
public:
    int minimumDeletions(string word, int k) 
    {
        // Step 1: Count character frequencies
        vector<int> count(26, 0);
        for (char c : word) 
        {
            count[c - 'a']++;
        }

        // Step 2: Store non-zero frequencies and sort
        vector<int> freqs;
        for (int c : count) 
        {
            if (c > 0)
            {
                freqs.push_back(c);
            } 
        }
        sort(freqs.begin(), freqs.end());
        int n = freqs.size();

        // Step 3: Prefix sum of frequencies
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) 
        {
            prefix[i + 1] = prefix[i] + freqs[i];
        }

        int total = prefix[n];
        int minDeletions = INT_MAX;

        // Step 4: Try each frequency as target
        for (int i = 0; i < n; ++i) 
        {
            int target = freqs[i];
            int maxAllowed = target + k;

            // Step 5: Binary search for upper bound
            int j = upper_bound(freqs.begin(), freqs.end(), maxAllowed) - freqs.begin();

            // Step 6: Compute deletions
            int deleteBelow = prefix[i];
            int deleteAbove = total - prefix[j] - (maxAllowed * (n - j));
            int deletions = deleteBelow + deleteAbove;

            minDeletions = min(minDeletions, deletions);
        }

        return minDeletions;
    }
};