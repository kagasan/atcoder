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
const ll INF = 1145141919810893364;
const ll MOD = 1000000007;
const ll NUM = 101010;

ll dp[2020][2020];

int main(){

    ll N, M;
    cin >> N >> M;
    V v(N + 1, 0);
    rep(i, N)cin >> v[i];
    sort(v.begin(), v.end());
    rep1(i, N)v[i] += v[i - 1];
    rep(i, 2020)rep(j, 2020)dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i, N)rep(j, M)if(dp[i][j] < INF){
        for(ll k = i + 1; k <= N; k++){
            chmin(dp[k][j + 1], dp[i][j] + (k - i) * (v[k] - v[i]));
        }
    }
    cout << dp[N][M] << endl;
    return 0;
}