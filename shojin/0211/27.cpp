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

int main(){

    ll N, H, A, B, C, D, E;
    cin >> N >> H >> A >> B >> C >> D >> E;
    ll ans = N * A;
    for(ll z = 0; z <= N; z++){
        ll h = H - z * E;
        if(h + B * (N - z)<= 0)continue;
        if(h + D * (N - z) > 0){
            chmin(ans, C * (N - z));
            continue;
        }
        ll ok = 0, ng = N - z;
        while(ok + 1 < ng){
            ll y = (ok + ng) / 2;
            ll x = N - y - z;
            if(h + B * x + D * y > 0)ok = y;
            else ng = y;
        }
        chmin(ans, A * (N - z - ok) + C * ok);
    }
    cout << ans << endl;

    return 0;
}