#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll dp[2020][2020];

int main(){

    for(ll i = 0; i < 2020; i++){
        for(ll j = 0; j < 2020; j++){
            dp[i][j] = 1;
        }
    }

    ll N, M;
    cin >> N >> M;
    vector<ll>S(N + 1, -1), T(M + 1, -2);
    for(ll i = 1; i <= N; i++){
        cin >> S[i];
    }
    for(ll i = 1; i <= M; i++){
        cin >> T[i];
    }
    for(ll i = 1; i <= M; i++){
        for(ll j = 1; j <= N; j++){
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            dp[i][j] %= MOD;
            if(S[j] != T[i]){
                dp[i][j] = (dp[i][j] + MOD - dp[i - 1][j - 1]) % MOD;
            }
        }
    }
    cout << dp[M][N] << endl;

    return 0;
}