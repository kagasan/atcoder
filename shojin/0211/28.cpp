#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P>IP;
typedef vector<ll> V;
typedef vector<V> V2;
typedef vector<vector<P> > G;
void g_dir(G &graph, ll a, ll b, ll w = 1){graph[a].push_back(P(b, w));}
void g_undir(G &graph, ll a, ll b, ll w = 1){g_dir(graph, a, b, w);g_dir(graph, b, a, w);}
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}
const ll INF = 1145141919;
const ll MOD = 1000000007;
const ll NUM = 101010;

ll mp[1111][1111];
ll H, W, C;
ll X(ll x, ll y){
    return 510 + x - y;
}
ll Y(ll x, ll y){
    return x + y;
}

ll cnt(ll x1, ll y1, ll x2, ll y2){
    if(x1 < 1 || y1 < 1)return -1;
    return mp[y2][x2] + mp[y1 - 1][x1 - 1] - mp[y2][x1 - 1] - mp[y1 - 1][x2];
}

int main(){

    rep(i, 1111)rep(j, 1111)mp[i][j] = 0;

    cin >> H >> W >> C;
    rep1(y, H)rep1(x, W){
        char c;
        cin >> c;
        if(c == 'o')mp[Y(x, y)][X(x, y)] = 1;
    }
    rep1(y, 1100)rep1(x, 1100)mp[y][x] += mp[y - 1][x];
    rep1(y, 1100)rep1(x, 1100)mp[y][x] += mp[y][x - 1];
    ll ans = 0;
    ll hoge = 0;
    rep1(i, C){
        hoge += 2 * i - 1;
        if(i < C)hoge += 2 * i - 1;
    }
    rep1(y, H){
        rep1(x, W){
            ll x2 = X(x, y), y2 = Y(x, y);
            ll x1 = x2 - (2 * C - 2);
            ll y1 = y2 - (2 * C - 2);
            // cout << x << ", " << y << " : " << x1 << ", " << y1 << " - " << x2 << ", " << y2 << " = " << cnt(x1, y1, x2, y2) << endl;
            // cout << x << ", " << y << " : " << cnt(x1, y1, x2, y2) << endl;
            if(cnt(x1, y1, x2, y2) == hoge)ans++;
        }
        // cout << endl;
    }

    cout << ans << endl;

    return 0;
}