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

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
ll W, H;
ll mp[100][100];
ll ans = 0;

void dfs(ll x, ll y, ll cnt = 0){
    if(mp[y][x] == 0)return;
    mp[y][x] = 0;
    cnt++;
    chmax(ans, cnt);
    rep(i, 4)dfs(x + dx[i], y + dy[i], cnt);
    mp[y][x] = 1;
}

int main(){

    cin >> W >> H;
    rep1(y, H)rep1(x, W)cin >> mp[y][x];
    rep1(y, H)rep1(x, W)dfs(x, y);
    cout << ans << endl;

    return 0;
}