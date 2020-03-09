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

ll p;
ll Fib[202020];
ll imos[202020];
ll ans[202020];
int main(){

    cin >> p;
    Fib[1] = 0;
    Fib[2] = 1;
    for(ll i = 3; i < 202020; i++){
        Fib[i] = (p * Fib[i - 1]) % MOD + Fib[i - 2];
        Fib[i] %= MOD;
    }
    for(ll i = 1; i < 202020; i++){
        imos[i] = (imos[i - 1] + Fib[i]) % MOD;
    }
    

    rep1(i, 10)cout << i << " : " << Fib[i] << endl;
    return 0;
    ll Q;
    cin >> Q;
    rep(i, Q){
        ll q;
        cin >> q;

    }
    
    return 0;
}