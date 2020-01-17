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
const ll INF = 1145141919810893;
const ll MOD = 1000000007;
const ll NUM = 101010;

int main(){

    ll N;
    cin >> N;
    vector<double>t(N), v(N);
    rep(i, N)cin >> t[i];
    rep(i, N)cin >> v[i];
    ll total = 0;
    rep(i, N)total += t[i];
    vector<double>mx(2 * total + 1, INF);
    ll now = 0;
    rep(i, N){
        rep(j, t[i]){
            ll t1 = now + j * 2;
            ll t2 = now + j * 2 + 1;
            chmin(mx[t1], v[i]);
            chmin(mx[t2], v[i]);
        }
        now += t[i] * 2;
        chmin(mx[now], v[i]);
    }
    mx[0] = 0;
    mx[total * 2] = 0;

    // for(ll i = 0; i <= total * 2; i++)cout << i * 0.5 << " : " << mx[i] << endl;

    rep(i, 2 * total + 1){
        chmin(mx[i + 1], mx[i] + 0.5);
    }
    rrep(i, 2 * total + 1){
        chmin(mx[i], mx[i + 1] + 0.5);
    }
    // for(ll i = 0; i <= total * 2; i++)cout << i * 0.5 << " : " << mx[i] << endl;
    double ans = 0;
    rep(i, 2 * total + 1){
        ans += (mx[i] + mx[i + 1]) * 0.25;
    }
    printf("%.10f\n", ans);

    return 0;
}