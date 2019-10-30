#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 1234567;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll N, M, K;
ll A[20202], dp[20202];

int main(){

    rep1(i, 20200)dp[i] = 1145141919810893364;
    cin >> N >> M >> K;
    rep1(i, N)cin >> A[i];
    rep(i, N){
        ll mn = A[i + 1], mx = A[i + 1];
        rep1(j, M){
            if(i + j > N)break;
            chmin(mn, A[i + j]);
            chmax(mx, A[i + j]);
            chmin(dp[i + j], dp[i] + K + j * (mx - mn));
        }
    }
    cout << dp[N] << endl;

    return 0;
}