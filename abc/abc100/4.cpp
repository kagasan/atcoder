#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;

ll cake[1010][3];

int main(){

    ll N, M;
    cin >> N >> M;
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < 3; j++){
            cin >> cake[i][j];
        }
    }
    ll ans = 0;
    for(ll i = 0; i < (1 << 3); i++){
        vector<P>v(N);
        for(ll j = 0; j < N; j++){
            ll tmp = 0;
            for(ll k = 0; k < 3; k++){
                if(i & (1 << k))tmp += cake[j][k];
                else tmp -= cake[j][k];
            }
            v[j] = P(tmp, j);
        }
        sort(v.begin(), v.end(), greater<P>());
        ll sum[3] = {};
        for(ll j = 0; j < M; j++){
            ll idx = v[j].second;
            for(ll k = 0; k < 3; k++){
                sum[k] += cake[idx][k];
            }
        }
        ans = max(ans, abs(sum[0])+abs(sum[1])+abs(sum[2]));
    }
    cout << ans << endl;

    return 0;
}
