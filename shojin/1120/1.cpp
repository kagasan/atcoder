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
typedef pair<P, ll> PI;
const ll dy[4] = {1, 0, -1, 0};
const ll dx[4] = {0, 1, 0, -1};

ll H, W;
char mp[555][555];
ll sx, sy;
ll flg[555][555][3];

string solve(){
    flg[sy][sx][0] = 1;
    queue<PI>Q;
    Q.push(PI(P(sx, sy), 0));
    while(!Q.empty()){
        ll x = Q.front().first.first;
        ll y = Q.front().first.second;
        ll z = Q.front().second;
        Q.pop();
        if(mp[y][x] == 'g')return "YES";
        rep(i, 4){
            ll ny = y + dy[i], nx = x + dx[i], nz = z;
            if(mp[ny][nx] == '@')continue;
            if(mp[ny][nx] == '#' && z == 2)continue;
            if(mp[ny][nx] == '#')nz = z + 1;
            if(flg[ny][nx][nz])continue;
            flg[ny][nx][nz] = 1;
            Q.push(PI(P(nx, ny), nz));
        }
    }
    return "NO";
}


int main(){
    
    rep(i, 555)rep(j, 555)mp[i][j] = '@';
    cin >> H >> W;
    rep1(y, H)rep1(x, W){
        cin >> mp[y][x];
        if(mp[y][x] == 's'){
            sx = x;
            sy = y;
        }
    }
    cout << solve() << endl;

    return 0;
}
