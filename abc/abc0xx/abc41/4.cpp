#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N, M;
    cin >> N >> M;
    ll ue[20][20] = {};
    for(ll i = 0; i < M; i++){
        ll x, y;
        cin >> x >> y;
        ue[y-1][x-1] = 1;
    }
    vector<ll>dp(1 << N, 0);
    vector<ll>flg(1 << N, 0);
    queue<ll>Q;
    Q.push(0);
    dp[0] = 1;
    while(!Q.empty()){
        ll state = Q.front();
        Q.pop();
        if(flg[state])continue;
        flg[state] = 1;
        for(ll i = 0; i < N; i++){
            if((1 << i) & state)continue;
            ll f = 0;
            for(ll j = 0; j < N; j++){
                if(ue[i][j] == 0)continue;
                if(((1 << j) & state) == 0)f = 1;
            }
            if(f)continue;
            Q.push(state + (1 << i));
            dp[state + (1 << i)] += dp[state];
        }
    }
    cout << dp[(1<<N)-1] << endl;

    return 0;
}
