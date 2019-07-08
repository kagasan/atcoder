#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

char mp[111][111];
int flg[111][111];

int main(){
    for(ll i = 0; i < 111; i++){
        for(ll j = 0; j < 111; j++){
            mp[i][j] = '#';
        }
    }
    ll H, W;
    cin >> H >> W;
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++)cin >> mp[y][x];
    }
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++){
            ll cnt = 0;
            for(ll dy = -1; dy <= 1; dy++){
                for(ll dx = -1; dx <= 1; dx++){
                    if(mp[y + dy][x + dx] == '#')cnt++;
                }
            }
            if(cnt < 9)continue;
            for(ll dy = -1; dy <= 1; dy++){
                for(ll dx = -1; dx <= 1; dx++){
                    flg[y + dy][x + dx] |= 1;
                }
            }
            flg[y][x] |= 2;
        }
    }
    ll f = 0;
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++){
            if(mp[y][x] == '#' && (flg[y][x] & 1) == 0)f = 1;
        }
    }
    if(f){
        cout << "impossible" << endl;
        return 0;
    }
    cout << "possible" << endl;
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++){
            if(flg[y][x] & 2)cout << "#";
            else cout << ".";
        }
        cout << endl;
    }
    
    return 0;
}
