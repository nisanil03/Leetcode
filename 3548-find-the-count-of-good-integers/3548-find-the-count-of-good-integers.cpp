long long tens[11] = {1};
long long C[11][11] = {{0}};
static array<char, 10> zero={0};
struct myHash {
    size_t operator()(const array<char, 10>& v) const {
        constexpr static array<size_t, 10> primes={3, 5, 17, 257, 3, 5, 17, 257, 3, 5};
        uint64_t h=0;
        for (int i = 0; i<10; i++) {
            h^= primes[i]*v[i];
            h+= (h << 4);
        }
        return h;
    }
};

class Solution {
public:
    using int2 = pair<long long, long long>;
    unordered_set<array<char,10>, myHash> seen;
    int n;

    void buildTens() {
        if (tens[1] == 10) return;
        for (int i=1; i<=10; i++) 
            tens[i]=tens[i-1]*10;
    }

    void Pascal() {
        if (C[0][0]==1) return;
        C[0][0]=1;
        for (int i=1; i<=10; i++) {
            C[i][0]=C[i][i]=1;
            for (int j=1; j<= i/2; j++) {
                C[i][j]=C[i][i-j]= C[i-1][j-1]+C[i-1][j];
            //  cout<<"C["<< i<<"]["<<j<<"]="<<C[i][j]<< ",";
            }
           // cout << endl;
        }
    }

    array<char, 10> pal(int x, int dz, int k) {
    //    cout<<"x="<<x;
        int sz=dz-(n&1);
        array<char, 10> freq={0};
        long long ans=tens[sz]*x;
        if (n&1){ 
            freq[x%10]++;
            x/=10;
        }
        for(int i=0; i<sz; i++){
            char r=x%10;
            freq[r]+=2;
            ans+=r*tens[sz-1-i];
            x/=10;
        }
        if (ans%k!=0) return zero;
        return freq;
    }

    long long perm(const array<char, 10>& freq) {
        int d=reduce(freq.begin(), freq.end(), 0);

        long long ans=1;
        if (freq[0]>0) {
            ans=C[d-1][freq[0]];
            d-=freq[0];
        }

        for (int i = 1; i <= 9; ++i) {
            if (freq[i] > 0) {
                ans*=C[d][freq[i]];
                d-=freq[i];
            }
        }

        return ans;
    }

    long long countGoodIntegers(int n, int k) {
        this->n=n;
        if (n <= 2)
            return 9 / k; // small n edge case

        buildTens();
        Pascal();

        const int h = (n+1)/2;
        long long ans = 0;

        for (int i=tens[h-1]; i<tens[h]; i++) {
            auto freq=pal(i, h, k);
            if (freq!=zero && !seen.count(freq)) {
                ans+=perm(freq);
                seen.insert(freq);
            }
        }
        return ans;
    }
};