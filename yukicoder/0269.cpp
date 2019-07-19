#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

const ll MOD = 1000000007;

ll dp[111][20202];

int main(){
    
    ll N, S, K;
    cin >> N >> S >> K;
    for(ll i = 0; i < N; i++){
        S -= i * K;
    }
    if(S < 0){
        cout << 0 << endl;
        return 0;
    }
    dp[0][0] = 1;
    for(ll i = 1; i <= N; i++){
        for(ll j = 0; j <= S; j++){
            ll pre = 20200;
            if(j - i >= 0)pre = j - i;
            dp[i][j] = (dp[i - 1][j] + dp[i][pre]) % MOD;
        }
    }
    cout << dp[N][S] << endl;

    return 0;
}