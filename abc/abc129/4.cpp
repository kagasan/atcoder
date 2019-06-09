#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

char mp[2020][2020];
ll ans = 0;

ll X[2020][2020];
ll Y[2020][2020];

int main(){
    
    for(ll i = 0; i < 2020; i++){
        for(ll j = 0; j < 2020; j++){
            mp[i][j] = '#';
        }
    }

    ll H, W;
    cin >> H >> W;
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++){
            cin >> mp[y][x];
        }
    }
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++){
            if(mp[y][x] == '#')continue;
            if(mp[y][x - 1] == '#'){
                ll cnt = 0;
                for(ll xx = x; mp[y][xx] == '.'; xx++)cnt++;
                for(ll xx = x; mp[y][xx] == '.'; xx++)X[y][xx] = cnt;
            }
            if(mp[y - 1][x] == '#'){
                ll cnt = 0;
                for(ll yy = y; mp[yy][x] == '.'; yy++)cnt++;
                for(ll yy = y; mp[yy][x] == '.'; yy++)Y[yy][x] = cnt;
            }
        }
    }
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++){
            ans = max(ans, X[y][x] + Y[y][x] - 1LL);
        }
    }
    
    cout << ans << endl;

    return 0;
}
