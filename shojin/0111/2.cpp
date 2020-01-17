#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P>IP;
typedef vector<ll> V;
typedef vector<V> V2;
typedef vector<vector<P> > G;
void g_dir(G &graph, ll a, ll b, ll w = 1){graph[a].push_back(P(b, w));}
void g_undir(G &graph, ll a, ll b, ll w = 1){g_dir(graph, a, b, w);g_dir(graph, b, a, w);}
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}
const ll INF = 1145141919;
const ll MOD = 1000000007;
const ll NUM = 101010;

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
    
    mod(ll m){
        M = m;
        N = 1;
        fact = vector<ll>(1, 1);
        inv = vector<ll>(1, 1);
        finv = vector<ll>(1, 1);
    }
};

ll solve(V &x){
    ll N = x.size();
    V v(N - 1);
    rep(i, N - 1)v[i] = i;
    ll res = 0;
    do{
        V flg(N + 1, 1);
        rep(i, N - 1){
            ll j = v[i];
            flg[j] = 0;
            for(;flg[j] == 0;j++){
                res += x[j + 1] - x[j];
            }
        }
    }while(next_permutation(v.begin(), v.end()));
    return res;
}

ll solve2(V &x){
    ll N = x.size();
    ll res = 0;
    mod m(MOD);
    ll tmp = 0, tmp2 = m.m_fact(N - 1), a = 1;
    for(ll i = 0; i + 1 < N; i++){
        ll len = x[i + 1] - x[i];
        res = (res + (len * (tmp + tmp2)) % MOD) % MOD;
        tmp = (tmp + tmp2) % MOD;
        tmp2 = m.m_divs((tmp2 * a) % MOD, a + 1);
        a++;
    }

    return res;
}

int main(){

    ll N;
    cin >> N;
    V x(N);
    rep(i, N)cin >> x[i];
    cout << solve2(x) << endl;
    
    return 0;
}