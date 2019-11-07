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
char mp[888][888];
ll flg[888][888];
ll sx, sy;
ll dy[4] = {0, 1, 0, -1};
ll dx[4] = {1, 0, -1, 0};

int main(){
    cin >> H >> W >> K;
    rep1(y, H)rep1(x, W){
        cin >> mp[y][x];
        flg[y][x] = INF;
        if(mp[y][x] == 'S'){
            sx = x;
            sy = y;
        }
    }
    flg[sy][sx] = 0;
    queue<P>Q;
    Q.push(P(sx, sy));
    while(!Q.empty()){
        ll x = Q.front().first;
        ll y = Q.front().second;
        Q.pop();
        rep(i, 4){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if(flg[ny][nx] < INF)continue;
            if(mp[ny][nx] == '#')continue;
            flg[ny][nx] = flg[y][x] + 1;
            Q.push(P(nx, ny));
        }
    }
    ll ans = INF;
    rep1(y, H)rep1(x, W)if(flg[y][x] <= K){
        chmin(ans, 1 + (H - y + K - 1) / K);
        chmin(ans, 1 + (y - 1 + K - 1) / K);
        chmin(ans, 1 + (W - x + K - 1) / K);
        chmin(ans, 1 + (x - 1 + K - 1) / K);
    }
    cout << ans << endl;

    return 0;
}