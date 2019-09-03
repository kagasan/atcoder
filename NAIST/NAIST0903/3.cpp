#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

char mp[110][110];

int main(){
    for(ll y = 0; y < 110; y++){
        for(ll x = 0; x < 110; x++){
            mp[y][x] = '#';
        }
    }
    ll N, M, D;
    cin >> N >> M >> D;
    for(ll y = 1; y <= N; y++){
        for(ll x = 1; x <= M; x++){
            cin >> mp[y][x];
        }
    }
    ll ans = 0;
    for(ll y = 1; y <= N; y++){
        for(ll x = 1; x <= M; x++){
            ll flg = 1;
            for(ll i = 0; i < D; i++){
                if(mp[y + i][x] == '#'){
                    flg = 0;
                    break;
                }
            }
            if(flg)ans++;
            flg = 1;
            for(ll i = 0; i < D; i++){
                if(mp[y][x + i] == '#'){
                    flg = 0;
                    break;
                }
            }
            if(flg)ans++;
        }
    }
    cout << ans << endl;

    return 0;    
}