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

int main(){

    ll N, M;
    cin >> N >> M;
    vector<ll>dp(1 << N, INF);
    dp[0] = 0;
    rep(i, M){
        ll a, b;
        cin >> a >> b;
        ll flg = 0;
        rep(j, b){
            ll c;
            cin >> c;
            flg += (1 << (c - 1));
        }
        rep(from, 1 << N){
            ll to = from | flg;
            chmin(dp[to], dp[from] + a);
        }
    }
    if(dp[(1 << N) - 1] == INF)cout << -1 << endl;
    else cout << dp[(1 << N) - 1] << endl;

    return 0;
}
