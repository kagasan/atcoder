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

ll dy[4] = {0, 1, 0, -1};
ll dx[4] = {1, 0, -1, 0};
ll H, W, N;
ll X[20], Y[20];
char mp[1010][1010];
ll flg[1010][1010];

ll solve(ll idx){
    ll sx = X[idx - 1], sy = Y[idx - 1];
    ll gx = X[idx], gy = Y[idx];
    rep(y, 1010)rep(x, 1010)flg[y][x] = INF;
    flg[sy][sx] = 0;
    queue<P>Q;
    Q.push(P(sx, sy));
    while(!Q.empty()){
        ll x = Q.front().first;
        ll y = Q.front().second;
        Q.pop();
        if(x == gx && y == gy){
            return flg[y][x];
        }
        rep(i, 4){
            ll nx = dx[i] + x;
            ll ny = dy[i] + y;
            if(mp[ny][nx] != 'X' && flg[ny][nx] == INF){
                flg[ny][nx] = flg[y][x] + 1;
                Q.push(P(nx, ny));
            }
        }
    }
    return 0;
}

int main(){

    rep(y, 1010)rep(x, 1010)mp[y][x] = 'X';
    
    cin >> H >> W >> N;
    rep1(y, H)rep1(x, W){
        cin >> mp[y][x];
        if(mp[y][x] == 'S'){
            X[0] = x;
            Y[0] = y;
        }
        if('1' <= mp[y][x] && mp[y][x] <= '9'){
            X[mp[y][x] - '0'] = x;
            Y[mp[y][x] - '0'] = y;
        }
    }
    ll ans = 0;
    rep1(i, N){
        ans += solve(i);
    }
    cout << ans << endl;

    return 0;
}