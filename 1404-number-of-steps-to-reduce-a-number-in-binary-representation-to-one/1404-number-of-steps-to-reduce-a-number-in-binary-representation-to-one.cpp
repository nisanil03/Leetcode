class Solution {
public:
    int numSteps(string s) {
        int steps = 0, carry = 0;
        for (int i = s.length() - 1; i > 0; i--) {
            int bit = s[i] & 1;
            steps += 1 + (bit ^ carry);
            carry |= bit;
        }
        return steps + carry;
    }
};