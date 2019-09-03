#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

ll mp[1010][1010];
ll X[1010101], Y[1010101];
ll val[1010][1010];

int main(){
    for(ll i = 0; i < 1010; i++){
        for(ll j = 0; j < 1010; j++){
            mp[i][j] = 1145141919;
        }
    }
    ll H, W;
    cin >> H >> W;
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++){
            cin >> mp[y][x];
            X[mp[y][x]] = x;
            Y[mp[y][x]] = y;
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= H * W; i++){
        ll x = X[i];
        ll y = Y[i];
        set<ll>S;
        for(ll j = 0; j < 4; j++){
            ll nx = x + dx[j];
            ll ny = y + dy[j];
            if(mp[y][x] > mp[ny][nx]){
                S.insert(val[ny][nx]);
                if(val[ny][nx] < 0)val[y][x] = -1;
            }
        }
        if(val[y][x] >= 0){
            if(S.size() == 0)val[y][x] = mp[y][x];
            else if(S.size() == 1)val[y][x] = *(S.begin());
            else val[y][x] = -1;
        }
        if(val[y][x] < 0)ans++;
    }
    cout << ans << endl;

    return 0;    
}