#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919810893;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll dp[1010][1010];
ll D[1010];
ll C[1010];

int main(){
    rep(i, 1010)rep(j, 1010)dp[i][j] = INF;
    ll N, M;
    cin >> N >> M;
    rep1(i, N)cin >> D[i];
    rep1(i, M)cin >> C[i];
    dp[0][0] = 0;
    for(ll d = 0; d + 1 <= M; d++){
        for(ll p = 0; p + 1 <= N; p++){
            chmin(dp[d + 1][p + 1], dp[d][p] + D[p + 1] * C[d + 1]);
            chmin(dp[d + 1][p], dp[d][p]);
        }
    }
    ll ans = INF;
    rep1(i, M)chmin(ans, dp[i][N]);
    cout << ans << endl;

    return 0;
}