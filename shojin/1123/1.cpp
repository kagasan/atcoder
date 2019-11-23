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

    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    if(x == 1)ans += 300000;
    if(x == 2)ans += 200000;
    if(x == 3)ans += 100000;
    if(y == 1)ans += 300000;
    if(y == 2)ans += 200000;
    if(y == 3)ans += 100000;
    if(x == y && x == 1)ans += 400000;
    cout << ans << endl;

    return 0;
}