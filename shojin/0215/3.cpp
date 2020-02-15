// ABC152E
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

ll m_pow(ll a, ll b){
    ll ret = 1;
    while(b > 0){
        if(b & 1)(ret *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return ret;
}

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

ll m_div(ll x){
    return m_pow(x, MOD - 2);
}

int main(){

    for(ll N; cin >> N;){
        V A(N);
        rep(i, N)cin >> A[i];
        map<ll, ll>cnt;
        for(auto a : A){
            map<ll, ll>tmp;
            ll x = a;
            for(ll j = 2; j * j <= x; j++){
                while(x % j == 0){
                    x /= j;
                    tmp[j]++;
                }
            }
            if(x > 1)tmp[x]++;
            for(auto p : tmp)chmax(cnt[p.first], p.second);            
        }
        ll m = 1;
        for(auto p : cnt)m = (m * m_pow(p.first, p.second)) % MOD;
        ll sum = 0;
        for(auto a : A){
            ll tmp = (m * m_inv(a)) % MOD;
            sum = (sum + tmp) % MOD;
        }
        cout << sum << endl;
    }
    
    return 0;
}