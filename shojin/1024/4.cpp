#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll s[370][3030];
ll dp[370][3030][5];

int main(){
    rep(i, 370)rep(j, 3030)rep(k, 5)dp[i][j][k] = INF;
    ll N, D;
    cin >> N >> D;
    rep1(d, D)rep1(n, N)cin >> s[d][n];
    dp[0][0][0] = 0;
    rep1(d, D){
        rep1(n, N){
            chmin(dp[d][n][1], dp[d - 1][0][0] + s[d][n]);
            chmin(dp[d][n][2], dp[d - 1][n][1] + s[d][n] * 9 / 10);
            chmin(dp[d][n][3], dp[d - 1][n][2] + s[d][n] * 7 / 10);
            chmin(dp[d][n][3], dp[d - 1][n][3] + s[d][n] * 7 / 10);
            rep1(i, 3)chmin(dp[d][0][0], dp[d][n][i]);
        }
    }
    cout << dp[D][0][0] << endl;

    return 0;
}