#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const ll INF = 1145141919;

ll N, M;
ll imos[22][101010];
ll cnt[22];
ll dp[1 << 20];
ll sum[1 << 20];

ll imos_cnt(ll x, ll l, ll r){
    return imos[x][r] - imos[x][l];
}

int main(){
    cin >> N >> M;
    for(ll i = 0; i < (1 << M); i++){
        dp[i] = INF;
    }
    for(ll i = 1; i <= N; i++){
        ll x;
        cin >> x;
        x--;
        imos[x][i]++;
        cnt[x]++;
    }
    for(ll i = 0; i < M; i++){
        for(ll j = 1; j <= N; j++){
            imos[i][j] += imos[i][j - 1];
        }
    }
    for(ll i = 0; i < (1 << M); i++){
        for(ll j = 0, k = 1; j < M; j++, k *= 2){
            if(i & k)sum[i] += cnt[j];
        }
    }
    dp[0] = 0;
    for(ll i = 0; i < (1 << M); i++){
        for(ll j = 0, k = 1; j < M; j++, k *= 2){
            if(i & k)continue;
            ll tmp = dp[i] + cnt[j];
            tmp -= imos_cnt(j, sum[i], sum[i] + cnt[j]);
            dp[i | k] = min(dp[i | k], tmp);
        }
    }
    cout << dp[(1 << M) - 1] << endl;

    return 0;    
}