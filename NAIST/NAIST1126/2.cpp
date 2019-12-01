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

ll X[202020];
ll Y[202020];

int main(){

	ll N;
    cin >> N;
    rep1(i, N)cin >> X[i];
    rep1(i, N)cin >> Y[i];
    ll ans = INF;
    rep1(i, N)chmin(ans, X[i] + Y[i]);
    cout << ans << endl;
    cout << 0 << endl;
    rep1(i, N){
        cout << min(X[i], ans) << endl;
    }
    cout << ans << endl;

    return 0;
}