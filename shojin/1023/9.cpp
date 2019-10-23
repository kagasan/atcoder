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

ll D, N;
ll T[222];
ll A[222], B[222], C[222];
ll dp[222][222];

int main(){
    rep(i, 222)rep(j, 222)dp[i][j] = -INF;
    cin >> D >> N;
    rep1(i, D)cin >> T[i];
    rep1(i, N)cin >> A[i] >> B[i] >> C[i];
    rep1(i, N)if(A[i] <= T[1] && T[1] <= B[i])dp[1][i] = 0;
    for(ll i = 1; i + 1 <= D; i++){
        for(ll j = 1; j <= N; j++){
            if(T[i] < A[j] || B[j] < T[i])continue;
            for(ll k = 1; k <= N; k++){
                if(T[i + 1] < A[k] || B[k] < T[i + 1])continue;
                chmax(dp[i + 1][k], dp[i][j] + abs(C[j] - C[k]));
            }
        }
    }
    ll ans = 0;
    rep1(i, N)chmax(ans, dp[D][i]);
    cout << ans << endl;

    return 0;
}