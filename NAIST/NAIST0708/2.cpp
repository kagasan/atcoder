#include "bits/stdc++.h"
using namespace std;

typedef pair<int, int>P;
char mp[500][500];
vector<P>pos[26];
int flg[26];
int ue[26][2];

int main(){
    int H, W;
    cin >> H >> W;
    for(int y = 0; y < H; y++){
        for(int x = 0; x < W; x++){
            cin >> mp[y][x];
            if(mp[y][x] != '.'){
                flg[mp[y][x] - 'A'] = 1;
                pos[mp[y][x] - 'A'].push_back(P(x, y));
            }
        }
    }
    for(int i = 0; i < 26; i++){
        if(flg[i] == 0)continue;
        if(abs(pos[i][0].first - pos[i][1].first) + abs(pos[i][0].second - pos[i][1].second) == 1){
            flg[i] = 0;
            continue;
        }
        int x2 = pos[i][1].first;
        int y2 = pos[i][1].second;
        int x = pos[i][0].first;
        int y = pos[i][0].second;
        while(x != x2){
            if(x < x2)x++;
            else if(x > x2)x--;
            if(mp[y][x] != '.' && mp[y][x] != 'A' + i){
                ue[i][0] |= (1 << (mp[y][x] - 'A'));
            }
        }
        while(y != y2){
            if(y < y2)y++;
            else if(y > y2)y--;
            if(mp[y][x] != '.' && mp[y][x] != 'A' + i){
                ue[i][0] |= (1 << (mp[y][x] - 'A'));
            }
        }
        x = pos[i][0].first;
        y = pos[i][0].second;
        while(y != y2){
            if(y < y2)y++;
            else if(y > y2)y--;
            if(mp[y][x] != '.' && mp[y][x] != 'A' + i){
                ue[i][1] |= (1 << (mp[y][x] - 'A'));
            }
        }
        while(x != x2){
            if(x < x2)x++;
            else if(x > x2)x--;
            if(mp[y][x] != '.' && mp[y][x] != 'A' + i){
                ue[i][1] |= (1 << (mp[y][x] - 'A'));
            }
        }
    }
    int ans = 0;
    int state = 0;
    for(int f = 1; f;){
        f = 0;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 2; j++){
                if(flg[i] == 0)continue;
                if(state & (1 << i))continue;
                if((state & (ue[i][j])) == ue[i][j]){
                    ans+=2;
                    state |= (1 << i);
                    f = 1;
                }
            }
        }    
    }


    cout << ans << endl;

    
    return 0;    
}