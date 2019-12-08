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

ll A[100][100];
ll B[100][100];
ll C[100][100];
ll H, W;

ll dp[85][85][6500];

int main(){

    cin >> H >> W;
    rep1(y, H)rep1(x, W)cin >> A[y][x];
    rep1(y, H)rep1(x, W)cin >> B[y][x];
    rep1(y, H)rep1(x, W)C[y][x] = abs(A[y][x] - B[y][x]);

    dp[1][1][0] = 1;
    rep1(y, H)rep1(x, W)rep(i, 6500)if(dp[y][x][i]){
        if(i + C[y][x] < 6500)dp[y + 1][x][i + C[y][x]] = dp[y][x + 1][i + C[y][x]] = 1;
        if(i - C[y][x] < 0)dp[y + 1][x][C[y][x] - i] = dp[y][x + 1][C[y][x] - i] = 1;
        else dp[y + 1][x][i - C[y][x]] = dp[y][x + 1][i - C[y][x]] = 1;
    }
    rep(i, 6500)if(dp[H + 1][W][i]){
        cout << i << endl;
        break;
    }
    return 0;
}