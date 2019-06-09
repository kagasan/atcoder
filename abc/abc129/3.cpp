#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;

ll dp[101010];
ll flg[101010];
ll N, M;

int main(){

    dp[0] = 1;
    cin >> N >> M;
    for(ll i = 0; i < M; i++){
        ll a;
        cin >> a;
        flg[a] = 1;
    }
    for(ll i = 0; i <= N; i++){
        if(flg[i + 1] == 0)dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
        if(flg[i + 2] == 0)dp[i + 2] = (dp[i + 2] + dp[i]) % MOD;
    }
    cout << dp[N] << endl;

    return 0;
}