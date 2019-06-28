#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll ans = 0, N, H, W;
    cin >> N >> H >> W;
    for(ll i = 0; i < N; i++){
        ll h, w;
        cin >> h >> w;
        if(h >= H && w >= W)ans++;
    }
    cout << ans << endl;

    return 0;
}