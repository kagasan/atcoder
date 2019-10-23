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

    ll N;
    cin >> N;
    ll dp[111][22] = {};
    ll v[111] = {};
    rep1(i, N)cin >> v[i];
    dp[1][v[1]] = 1;
    for(ll i = 1; i + 1 < N; i++){
        for(ll j = 0; j <= 20; j++){
            ll nxt = j + v[i + 1];
            if(nxt <= 20)dp[i + 1][nxt] += dp[i][j];
            nxt = j - v[i + 1];
            if(nxt >= 0)dp[i + 1][nxt] += dp[i][j];
        }
    }
    cout << dp[N - 1][v[N]] << endl;

    return 0;
}