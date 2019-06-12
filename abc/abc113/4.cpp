#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll H, W, K;
ll mat[10][10];
ll umu[10];

void dfs(ll nxt = 1){
    // if(nxt == W){
    //     for(ll i = 1; i < nxt; i++)cout << umu[i];
    //     cout << endl;
    // }
    if(nxt == W){
        for(ll to = 1; to <= W; to++){
            if(umu[to - 1])mat[to - 1][to]++;
            else if(umu[to])mat[to + 1][to]++;
            else mat[to][to]++;
        }
        return;
    }
    umu[nxt] = 0;
    dfs(nxt + 1);
    if(umu[nxt - 1] == 0){
        umu[nxt] = 1;
        dfs(nxt + 1);
    }
}

int main(){

    cin >> H >> W >> K;
    dfs();
    ll dp[110][10] = {};
    dp[0][1] = 1;
    for(ll y = 0; y < H; y++){
        for(ll from = 1; from <= W; from++){
            for(ll to = 1; to <= W; to++){
                dp[y + 1][to] += (dp[y][from] * mat[from][to]) % MOD;
                dp[y + 1][to] %= MOD;
            }
        }
    }
    cout << dp[H][K] << endl;

    return 0;
}