#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll cnt[3][33];
ll D[33][33];


int main(){

    ll N, C;
    cin >> N >> C;
    for(ll f = 1; f <= C; f++){
        for(ll t = 1; t <= C; t++){
            cin >> D[f][t];
        }
    }
    for(ll y = 1; y <= N; y++){
        for(ll x = 1; x <= N; x++){
            ll c;
            cin >> c;
            cnt[(x + y) % 3][c]++;
        }
    }
    ll ans = 1000000000LL;
    for(ll a = 1; a <= C; a++){
        for(ll b = 1; b <= C; b++){
            if(a == b)continue;
            for(ll c = 1; c <= C; c++){
                if(b == c)continue;
                if(a == c)continue;
                ll to[3] = {a, b, c};
                ll tmp = 0;
                for(ll i = 0; i < 3; i++){
                    for(ll j = 1; j <= C; j++){
                        tmp += D[j][to[i]] * cnt[i][j];
                    }
                }
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
