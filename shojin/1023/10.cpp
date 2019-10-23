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

ll N, W, H;
ll X[100], Y[100];

ll R2(ll x1, ll y1, ll x2, ll y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

ll check(ll ox, ll oy, ll px, ll py){
    ll r2 = R2(ox, oy, px, py);
    if(ox * ox < r2)return 1;
    if(oy * oy < r2)return 1;
    if((W - ox) * (W - ox) < r2)return 1;
    if((H - oy) * (H - oy) < r2)return 1;
    return 0;    
}

int main(){

    cin >> N >> W >> H;
    rep(i, N)cin >> X[i] >> Y[i];
    ll ans = 0;
    rep(a, N)rep(b, N)rep(c, N)rep(d, N){
        if(a == b || a == c || a == d)continue;
        if(b == c || b == d || c == d)continue;
        if(check(X[a], Y[a], X[b], Y[b]))continue;
        if(check(X[c], Y[c], X[d], Y[d]))continue;
        ll ab2 = R2(X[a], Y[a], X[b], Y[b]);
        ll cd2 = R2(X[c], Y[c], X[d], Y[d]);
        if(ab2 <= cd2)continue;
        ll ac2 = R2(X[a], Y[a], X[c], Y[c]);
        ll A = ac2, B = cd2, C = ab2;
        if(C - A - B >= 0 && 4 * A * B < (C - A - B) * (C - A - B))ans++;
    }
    cout << ans << endl;

    return 0;
}