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
const ll INF = 1145141919810893LL;
const ll MOD = 1000000007;
const ll NUM = 101010;
template<class T> T ijo_min(set<T> &S, const T &x){
    return *S.lower_bound(x);
}
int main(){

    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    set<ll>A, B;
    A.insert(INF);
    B.insert(INF);
    ll ans = 0;
    rep(i, N){
        ll x;
        cin >> x;
        A.insert(x);
    }
    rep(i, M){
        ll x;
        cin >> x;
        B.insert(x);
    }
    for(ll t = 0, pos = 0; t < INF;pos ^= 1){
        if(pos){
            t = ijo_min(B, t) + Y;
            if(t < INF)ans++;
        }
        else{
            t = ijo_min(A, t) + X;
        }
    }
    cout << ans << endl;

    return 0;
}