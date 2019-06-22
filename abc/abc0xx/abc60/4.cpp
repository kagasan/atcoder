#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    vector<ll>v[4];
    ll N, W;
    cin >> N >> W;
    ll w0, v0;
    cin >> w0 >> v0;
    v[0].push_back(v0);
    for(ll i = 1; i < N; i++){
        ll wi, vi;
        cin >> wi >> vi;
        v[wi - w0].push_back(vi);
    }
    vector<ll>sum[4];
    for(ll i = 0; i < 4; i++){
        sum[i].push_back(0);
        sort(v[i].begin(), v[i].end(), greater<ll>());
        for(ll j = 0; j < v[i].size(); j++){
            sum[i].push_back(sum[i][j] + v[i][j]);
        }
    }
    ll ans = 0;
    for(ll a = 0; a < sum[0].size(); a++){
        for(ll b = 0; b < sum[1].size(); b++){
            for(ll c = 0; c < sum[2].size(); c++){
                for(ll d = 0; d < sum[3].size(); d++){
                    ll w = w0 * a + (w0 + 1) * b + (w0 + 2) * c + (w0 + 3) * d;
                    if(w > W)continue;
                    ans = max(ans, sum[0][a] + sum[1][b] + sum[2][c] + sum[3][d]);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
