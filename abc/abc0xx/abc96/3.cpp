#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll H, W;
ll mp[55][55];
ll f[55][55];

int main(){
    
    cin >> H >> W;
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++){
            char c;
            cin >> c;
            if(c == '#')mp[y][x] = 1;
        }
    }
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++){
            if(mp[y][x] && mp[y][x + 1]){
                f[y][x] = 1;
                f[y][x + 1] = 1;
            }
            if(mp[y][x] && mp[y + 1][x]){
                f[y][x] = 1;
                f[y + 1][x] = 1;
            }
        }
    }
    ll flg = 1;
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++){
            if(mp[y][x] && f[y][x] == 0)flg = 0;
        }
    }
    if(flg)cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}