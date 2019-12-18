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

ll H, W, K;

ll mp[3030][3030];
ll down[3030][3030];
ll up[3030][3030];
ll naname[3030][3030];
ll mn[3030][3030];

ll solve(ll X, ll Y){
    ll ret = 0;
    priority_queue<P, vector<P>, greater<P> >Q;
    for(ll i = 0;;i++){
        ll x = X + i, y = Y + i;
        if(x > W || y > H)break;
        Q.push(P(i, down[y][x]));
        while(!Q.empty() && (i - Q.top().first) >= Q.top().second)Q.pop();
        if(Q.empty())continue;
        chmax(ret, min(up[y][x], Q.top().second));
    }
    return ret;
}

int main(){
    
    cin >> H >> W >> K;
    rep(i, K){
        ll a, b;
        cin >> a >> b;
        mp[a][b] = 1;
    }
    
    rep1(x, W)rrep1(y, H)down[y][x] = (mp[y][x] ? 0: down[y + 1][x] + 1);
    rep1(x, W)rep1(y, H)up[y][x] = (mp[y][x] ? 0: up[y - 1][x] + 1);
    rrep1(y, H)rep1(x, W)naname[y][x] = (mp[y][x] ? 0: naname[y + 1][x + 1] + 1);
    rep1(x, W)rep1(y, H)chmin(down[y][x], naname[y][x]);

    ll ans = 0;
    rep1(y, H)chmax(ans, solve(1, y));
    rep1(x, W)chmax(ans, solve(x, 1));
    cout << ans << endl;

    return 0;
}