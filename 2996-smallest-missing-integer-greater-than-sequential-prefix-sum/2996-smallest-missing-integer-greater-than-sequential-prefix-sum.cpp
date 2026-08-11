class Solution {
public:
    int missingInteger(vector<int>& A) {
        int sum = A[0];
        bitset<52> seen;
        bool seq = true;

        seen.set(A[0]);

        for (int i = 1; i < A.size(); i++) {
            if (seq && A[i] == A[i - 1] + 1)
                sum += A[i];
            else {
                seq = false;

                if (sum > 50)
                    return sum;
            }

            seen.set(A[i]);
        }

        for (int i = sum; i < 52; i++)
            if (!seen.test(i))
                return i;

        return sum;
    }
};