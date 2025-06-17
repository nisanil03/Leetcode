const int MOD = 1000000007;

class Solution 
{
public:
//base to the power exp
long long exponent(long long base, long long exp, long long mod) 
    {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
//fermats little theorem 
//this states is n is prime, a^n-1 mod p = 1 ; dividing by a -> a^n-2 mod p is equivalent to 1/a mod p
long long modInverse(long long x, long long mod) 
    {
        return exponent(x, mod - 2, mod);
    }


// combinations function
long long nCr(int n, int r, vector<long long>& fact) 
    {
        return fact[n] * modInverse(fact[r], MOD) % MOD * modInverse(fact[n - r], MOD) % MOD;
        //we use fermats theorem instead of n!/r!(n-r)! since long long cant hold it sometimes
    }

int countGoodArrays(int n, int m, int k) 
    {
        //computing factorials which are needed
        vector<long long> fact(n + 1, 1);
        for (int i = 2; i <= n; ++i) 
            fact[i] = fact[i - 1] * i % MOD;
    
        long long result = nCr(n - 1, k, fact);//for an array of size n, there are n-1 adjacent positions, we chooose k of n-1 positions.
        result = result * m % MOD; //each of the k pairs can have m values
        result = result * exponent(m - 1, n - k - 1, MOD) % MOD; // there are (n - 1) - k adjacent remainng, each of these have m-1 allowed values (we compare with previous adjacency)
        return result;
    }
};