//
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
void add(ll &a, const ll &b){
    a = (a + b) % MOD;
}
void mlt(ll &a, const ll &b){
    a = (a * b) % MOD;
}


ll N, C;
ll A[444], B[444];

ll dp[444][444];

int main(){

    cin >> N >> C;
    rep1(i, N)cin >> A[i];
    rep1(i, N)cin >> B[i];
    rep1(i, N)if(A[i] != B[i])return 1;
    dp[1][0] = 1;
    rep1(i, C)dp[1][i] = (dp[1][i - 1] * A[1]) % MOD;
    for(ll i = 1; i < N; i++){
        for(ll j = 0; j <= C; j++){
            add(dp[i + 1][j], dp[i][j]);
            for(ll k = j + 1, tmp = (dp[i][j] * A[i + 1]) % MOD; k <= C; k++, mlt(tmp, A[i + 1])){
                add(dp[i + 1][k], tmp);
            }
        }
    }
    // rep1(i, N){
    //     for(ll c = 0; c <= C; c++)cout << dp[i][c] << " ";
    //     cout << endl;
    // }
    cout << dp[N][C] << endl;

    return 0;
}
