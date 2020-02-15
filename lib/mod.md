# 簡単なやつ
```cpp
const ll MOD = 1000000007;

// デカイ割り算はこちらで
ll m_inv(ll a){
    ll b = MOD, u = 1, v = 0;
    while(b){
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD; 
    if (u < 0) u += MOD;
    return u;
}

// サイズ可変mod
class mod{
    public:
    ll N, M;
    vector<ll>fact;
    vector<ll>inv;
    vector<ll>finv;

    ll m_plus(ll a, ll b){return (a + b) % M;}
    ll m_minus(ll a, ll b){return (a + M - b) % M;}
    ll m_times(ll a, ll b){return (a * b) % M;}
    ll m_pow(ll a, ll b){
        ll ret = 1;
        while(b > 0){
            if(b & 1)(ret *= a) %= MOD;
            (a *= a) %= MOD;
            b >>= 1;
        }
        return ret;
    }

    void update(ll n){
        if(N > n)return;
        for(ll i = N; i <= n; i++){
            fact.push_back(m_times(fact[i - 1], i));
            inv.push_back(m_pow(i, M - 2));
            finv.push_back(m_times(finv[i - 1], inv[i]));
        }
        N = n + 1;
    }

    // 除算
    ll m_divs(ll a, ll b){
        if(N <= b)update(b);
        return m_times(a, inv[b]);
    }

    // N種の要素を並び替えてできる通りの数
    ll m_fact(ll a){
        if(N <= a)update(a);
        return fact[a];
    }

    // 階乗で割る
    ll m_finv(ll a){
        if(N <= a)update(a);
        return finv[a];
    }

    // N種の要素からk個取り出して並べる通りの数
    ll m_nPk(ll n, ll k){
        return m_times(m_fact(n), m_finv(n - k));
    }
    // N種の要素からk個を選ぶ通りの数
    // a個の赤い玉とb個の青い球を並び替える通りは(a+b)C(a)
    ll m_nCk(ll n, ll k){
        return m_times(m_nPk(n, k), m_finv(k));
    }
    // N種の要素からk個を選ぶ通りの数(重複して良い)
    ll m_nHk(ll n, ll k){
        return m_nCk(n + k - 1, k);
    }
    
    mod(ll m = MOD){
        M = m;
        N = 1;
        fact = vector<ll>(1, 1);
        inv = vector<ll>(1, 1);
        finv = vector<ll>(1, 1);
    }
};
```
```cpp
// string numberをmodとる
ll smod(string s){
    ll ret = 0;
    rep(i, s.size())ret = (ret * 10 + s[i] - '0') % MOD;
    return ret;
}
```