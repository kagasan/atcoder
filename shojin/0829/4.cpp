#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};
const ll INF = 1145141919;
ll N;
ll dp[1 << 18][18];
ll A[18], B[18];

int main(){
    
    cin >> N;
    for(ll i = 0; i < (1 << 18); i++){
        for(ll j = 0; j < 18; j++){
            dp[i][j] = INF;
        }
    }
    for(ll i = 0; i < N; i++){
        ll a, b;
        cin >> a >> b;
        A[i] = a;
        B[i] = b - a;
        dp[1 << i][i] = 0;
    }
    for(ll i = 0; i < (1 << N); i++){
        for(ll j = 0; j < N; j++){
            if(dp[i][j] == INF)continue;
            for(ll k = 0; k < N; k++){
                if(i & (1 << k))continue;
                dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], max(B[j] + A[k], dp[i][j]));
            }
        }
    }
    ll ans = INF;
    for(ll i = 0; i < N; i++){
        ans = min(ans, dp[(1 << N) - 1][i]);
    }
    cout << ans << endl;

    return 0;
}