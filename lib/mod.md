# 簡単なやつ
```cpp
const ll MOD = 1000000007;

ll mod_plus(ll a, ll b){return (a + b) % MOD;}
ll mod_minus(ll a, ll b){return (a + MOD - b) % MOD;}
ll mod_times(ll a, ll b){return (a * b) % MOD;}
ll mod_pow(ll a, ll b){
    ll ret = 1;
    while(b > 0){
        if(b & 1)(ret *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return ret;
}
ll mod_fact(ll a){
    ll ret = 1;
    for(ll i = 1; i <= a; i++)ret = (ret * i) % MOD;
    return ret;
}
```
