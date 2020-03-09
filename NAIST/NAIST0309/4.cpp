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

ll fib[2020202];

int main(){

    ll N, p;
    cin >> N >> p;
    ll ans = 0;
    fib[1] = 0;
    fib[2] = 1;
    for(ll i = 3; i <= N; i++){
        fib[i] = (p * fib[i - 1]) % MOD + fib[i - 2];
        fib[i] %= MOD;
    }
    ll tmp = 0;
    rep1(i, N){
        tmp = (tmp + fib[i]) % MOD;
        ans += (tmp * fib[i]) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
    
    return 0;
}