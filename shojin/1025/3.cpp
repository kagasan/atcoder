#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 100000;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}
void mod_plus(ll &a, ll b){a = (a + b) % MOD;}

ll dx[2] = {1, 0};
ll dy[2] = {0, 1};
// y, x, dir, lst
ll dp[111][111][2][2];

int main(){

    ll W, H;
    cin >> W >> H;
    dp[1][1][0][1] = 1;
    dp[1][1][1][1] = 1;
    rep1(y, H)rep1(x, W)rep(d, 2){
        mod_plus(dp[y + dy[d]][x + dx[d]][d][0], dp[y][x][d][0]);
        mod_plus(dp[y + dy[d]][x + dx[d]][d][0], dp[y][x][d][1]);
        mod_plus(dp[y + dy[d ^ 1]][x + dx[d ^ 1]][d ^ 1][1], dp[y][x][d][0]);
    }
    ll ans = 0;
    rep(d, 2)rep(f, 2)mod_plus(ans, dp[H][W][d][f]);
    cout << ans << endl;

    return 0;
}