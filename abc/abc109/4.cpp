#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll mp[500][500];
ll tmp[500][500];

int main(){

    ll H, W;
    cin >> H >> W;

    for(ll y = 0; y < H; y++){
        for(ll x = 0; x < W; x++){
            cin >> mp[y][x];
            tmp[y][x] = mp[y][x];
        }
    }
    ll cnt = 0;
    for(ll y = 0; y < H; y++){
        for(ll x = 0; x < W; x++){
            if(tmp[y][x] % 2 == 0)continue;
            if(x + 1 == W && y + 1 == H)continue;
            cnt++;
            tmp[y][x]--;
            if(x + 1 == W)tmp[y+1][x]++;
            else tmp[y][x+1]++;
        }
    }
    cout << cnt << endl;
    for(ll y = 0; y < H; y++){
        for(ll x = 0; x < W; x++){
            if(mp[y][x] % 2 == 0)continue;
            if(x + 1 == W && y + 1 == H)continue;
            cnt++;
            mp[y][x]--;
            if(x + 1 == W){
                mp[y+1][x]++;
                printf("%d %d %d %d\n", y + 1, x + 1, y + 2, x + 1);
            }
            else{
                mp[y][x+1]++;
                printf("%d %d %d %d\n", y + 1, x + 1, y + 1, x + 2);
            }
        }
    }
    

    return 0;
}
