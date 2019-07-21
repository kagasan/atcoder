#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll X[101010];
ll Y[101010];

ll XX[101010];
ll YY[101010];

int main(){
    
    ll H, W, K, N;
    cin >> H >> W >> K >> N;
    vector<ll>y(N), x(N);
    for(ll i = 0; i < N; i++){
        cin >> y[i] >> x[i];
        Y[y[i]]++;
        X[x[i]]++;
    }
    ll ans = 0;
    for(ll yy = 1; yy <= H; yy++)YY[Y[yy]]++;
    for(ll xx = 1; xx <= W; xx++)XX[X[xx]]++;
    for(ll i = 0; i <= K; i++){
        ll j = K - i;
        ans += YY[i] * XX[j];
    }
    for(ll i = 0; i < N; i++){
        if(X[x[i]] + Y[y[i]] == K)ans--;
        if(X[x[i]] + Y[y[i]] == K + 1)ans++;
    }
    cout << ans << endl;

    return 0;
}
