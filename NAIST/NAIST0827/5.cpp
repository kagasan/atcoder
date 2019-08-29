#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;
typedef pair<P, P>PP;

const ll INF = 1145141919810893;

ll H, W;
ll mp[35][35];
ll dp[1050][35][35];

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main(){

    for(ll i = 0; i < 35; i++){
        for(ll j = 0 ; j < 35; j++){
            mp[i][j] = -1;
        }
    }
    for(ll i = 0; i < 35; i++){
        for(ll j = 0 ; j < 35; j++){
            for(ll k = 0; k < 1050; k++){
                dp[k][i][j] = INF;
            }
        }
    }
    cin >> H >> W;
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++){
            cin >> mp[y][x];
        }
    }
    ll ans = INF;
    dp[0][1][1] = 0;
    for(ll step = 0; step <= H * W; step++){
        for(ll y = 1; y <= H; y++){
            for(ll x = 1; x <= W; x++){
                if(dp[step][y][x] == INF)continue;
                // if(dp[step][y][x] < ans){
                //     cout << step << ", " << x << ", " << y << " -> " << dp[step][y][x] << endl;
                // }
                if(y == H && x == W)ans = min(ans, dp[step][y][x]);
                for(ll i = 0; i < 4; i++){
                    ll nstep = step + 1;
                    ll ny = y + dy[i];
                    ll nx = x + dx[i];
                    if(mp[ny][nx] < 0)continue;
                    ll nscore = dp[step][y][x] + mp[ny][nx] * (step * 2 + 1);
                    dp[nstep][ny][nx] = min(dp[nstep][ny][nx], nscore);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;    
}