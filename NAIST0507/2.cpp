#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    int mp[20][10];
    int flg[20][10];

    for(int h; cin >> h, h;){
        for(int y = 0; y < 20; y++){
            for(int x = 0; x < 10; x++){
                mp[y][x] = 0;
            }
        }
        for(int y = h; y >= 1; y--){
            for(int x = 1; x <= 5; x++){
                cin >> mp[y][x];
            }
        }
        int ans = 0;
        for(int f = 1; f;){
            f = 0;
            for(int y = 0; y < 20; y++){
                for(int x = 0; x < 10; x++){
                    flg[y][x] = 0;
                }
            }
            for(int y = 1; y <= h; y++){
                for(int x = 1; x <= 3; x++){
                    if(mp[y][x] == 0)continue;
                    if(mp[y][x] == mp[y][x + 1] && mp[y][x+1] == mp[y][x+2]){
                        flg[y][x] = 1;
                        flg[y][x+1] = 1;
                        flg[y][x+2] = 1;
                    }
                }
            }
            for(int y = 1; y <= h; y++){
                for(int x = 1; x <= 5; x++){
                    if(flg[y][x] == 0)continue;
                    f = 1;
                    ans+=mp[y][x];
                    mp[y][x] = 0;
                }
            }
            for(int x = 1; x <= 5; x++){
                for(int y = 1; y <= h; y++){
                    if(mp[y][x])continue;
                    for(int y2 = y; y2 <= h; y2++){
                        if(mp[y2][x]){
                            swap(mp[y][x], mp[y2][x]);
                            break;
                        }
                    }
                }
            }
            // for(int y = h; y >= 1; y--){
            //     for(int x = 1; x <= 5; x++){
            //         cout << mp[y][x];
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }
        cout << ans << endl;
    }

    return 0;
}