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

ll ans = 0;
ll N, T;

ll dp[3030][3030];

int main(){

    cin >> N >> T;
    vector<P>v(N);
    rep(i, N)cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    rep(i, N){
        ll A = v[i].first;
        ll B = v[i].second;
        for(ll t = 0; t <= T; t++)dp[i + 1][t] = dp[i][t];
        for(ll t = 0; t < T; t++){
            ll nxt = min(T, t + A);
            chmax(dp[i + 1][nxt], dp[i][t] + B);
        }
    }
    for(ll t = 0; t <= T; t++)chmax(ans, dp[N][t]);
    cout << ans << endl;

    return 0;
}