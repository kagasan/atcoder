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

ll N, A;
ll dp[55][2600];

int main(){

    dp[0][0] = 1;
    cin >> N >> A;
    rep(i, N){
        ll x;
        cin >> x;
        rrep1(num, N)rrep1(sum, 2500){
            ll from_sum = sum - x;
            if(from_sum < 0)continue;
            dp[num][sum] += dp[num - 1][from_sum];
        }
    }
    ll ans = 0;
    rep1(num, N)rep1(sum, 2500)if(num * A == sum){
        ans += dp[num][sum];
    }
    cout << ans << endl;

    return 0;
}