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

ll dp[100][100];
ll flg[100][100];

int main(){

    ll W, H, N;
    cin >> W >> H >> N;
    rep(i, N){
        ll x, y;
        cin >> x >> y;
        flg[y][x] = 1;
    }
    dp[1][1] = 1;
    rep1(y, H){
        rep1(x, W){
            if(flg[y][x]){
                dp[y][x] = 0;
                continue;
            }
            dp[y + 1][x] += dp[y][x];
            dp[y][x + 1] += dp[y][x];
        }
    }
    cout << dp[H][W] << endl;

    return 0;
}