#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, MA, MB;
    cin >> N >> MA >> MB;
    vector<vector<ll> >dp(500, vector<ll>(500, 114514));
    dp[0][0] = 0;
    for(ll i = 0; i < N; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        for(ll ta = 444; ta >= 0; ta--){
            for(ll tb = 444; tb >= 0; tb--){
                ll fa = ta - a;
                ll fb = tb - b;
                if(fa < 0 || fb < 0)continue;
                dp[ta][tb] = min(dp[ta][tb], dp[fa][fb] + c);
            }
        }
    }
    ll ans = 114514;
    for(ll a = MA, b = MB;;a += MA, b+= MB){
        if(a > 444 || b > 444)break;
        ans = min(ans, dp[a][b]);
    }
    if(ans == 114514)cout << "-1" << endl;
    else cout << ans << endl;
    
    return 0;
}
