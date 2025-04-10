#define ll long long
class Solution {
public:
    ll flrdiv(ll a,ll b){
        ll div = a/b;
        if(a%b!=0 && a<0) div--;
        return div;
    }
    ll power(ll base,ll exp){
        ll ans = 1;
        while(exp>0){
            if(exp&1) ans = ans*base;
            base = base*base;
            exp/=2;
        }
        return ans;
    }

    ll f(ll x,ll lim){
        if(x<0) return 0;
        string s = to_string(x);
        ll n = s.size();
        ll cnt = 0;
        //numbers having fewer than n digits.
        for(int i = 1;i<n;i++){
            if(i==1) cnt+= (lim+1);
            else cnt+= (ll)lim*power(lim+1,i-1);
        }

        ll curcnt = 0;
        bool ok = true;
        for(int i =0;i<n;i++){
            ll dig = s[i]-'0';
            ll  sd = (i==0 && n>1)?1:0;
            for(int j = sd;j<dig;j++){
                if(j>lim) break;
                curcnt+=power(lim+1,n-i-1);
            }
            if(dig>lim){
                ok = false;
                break;
            }
        }
        if(ok) curcnt++;
        return  cnt + curcnt;
    }
 
 
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        ll l = s.size();
        ll p = stoll(s);
        ll tl = 1;

        for(ll i =0;i<l;i++) tl*=10;

        if(finish<p) return 0;
        ll pmn = -flrdiv(-start+p,tl);
        ll pmx = flrdiv(finish-p,tl);

        if(pmn>pmx) return 0;
        
        return f(pmx,limit)- f(pmn-1,limit);
    }
};