#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N, K;
    cin >> N >> K;
    ll v[55];
    for(ll i = 1; i <= N; i++)cin >> v[i];
    ll ans = 0;
    ll dp[55][55][105];
    for(ll i = 0; i < 55; i++){
        for(ll j = 0; j < 55; j++){
            for(ll k = 0; k < 105; k++){
                dp[i][j][k] = -1000000000LL;
            }
        }
    }
    dp[0][N + 1][0] = 0;
    for(ll d = N + 1; d >= 1; d--){
        for(ll l = 0; l + d <= N + 1; l++){
            ll r = l + d;
            for(ll k = 0; k <= K; k++){
                ans = max(ans, dp[l][r][k]);
                dp[l + 1][r][k + 1] = max(dp[l + 1][r][k + 1], dp[l][r][k] + v[l + 1]);
                dp[l + 1][r][k + 2] = max(dp[l + 1][r][k + 2], dp[l][r][k]);
                dp[l][r - 1][k + 1] = max(dp[l][r - 1][k + 1], dp[l][r][k] + v[r - 1]);
                dp[l][r - 1][k + 2] = max(dp[l][r - 2][k + 2], dp[l][r][k]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
