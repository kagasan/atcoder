#include "bits/stdc++.h"
using namespace std;

int h[220][220];
int u[220][220];
int ans[7];
void init(){
    for(int i = 1; i <= 6; i++)ans[i] = 0;
    for(int i = 0; i < 220; i++){
        for(int j = 0; j < 220; j++){
            ans[u[i][j]]++;
            u[i][j] = 0;
            h[i][j] = 0;
        }
    }

}

int dice[6];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void rot(int a){
    int tmp[6];
    for(int i = 0; i < 6; i++)tmp[i] = dice[i];
    if(a == 0){
        dice[0] = tmp[3];
        dice[1] = tmp[0];
        dice[5] = tmp[1];
        dice[3] = tmp[5];
    }
    if(a == 1){
        dice[0] = tmp[4];
        dice[2] = tmp[0];
        dice[4] = tmp[5];
        dice[5] = tmp[2];
    }
    if(a == 2){
        dice[0] = tmp[1];
        dice[1] = tmp[5];
        dice[5] = tmp[3];
        dice[3] = tmp[0];
    }
    if(a == 3){
        dice[0] = tmp[2];
        dice[2] = tmp[5];
        dice[4] = tmp[0];
        dice[5] = tmp[4];
    }
}

int calc[7][7] = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 3, 5, 2, 4, 0},
    {0, 4, 0, 1, 6, 0, 3},
    {0, 2, 6, 0, 0, 1, 5},
    {0, 5, 1, 0, 0, 6, 2},
    {0, 3, 0, 6, 1, 0, 4},
    {0, 0, 4, 2, 5, 3, 0}
};

void drop(int t, int f){
    dice[0] = t;
    dice[1] = f;
    dice[2] = calc[t][f];
    dice[3] = 7 - dice[1];
    dice[4] = 7 - dice[2];
    dice[5] = 7 - dice[0];
    for(int x = 100, y = 100, cnt = 0;cnt < 5;cnt++){
        // cout << x << ", " << y << endl;
        int idx = 0;
        int val = 0;
        for(int i = 1; i <= 4; i++){
            if(h[y][x] > h[y + dy[i-1]][x + dx[i-1]]){
                if(val < dice[i]){
                    idx = i;
                    val = dice[i];
                }
            }
        }
        if(val < 4){
            h[y][x]++;
            u[y][x] = dice[0];
            break;
        }
        else{
            rot(idx - 1);
            y += dy[idx - 1];
            x += dx[idx - 1];
        }
    }
}
int main(){

    for(int n; cin >> n, n; ){
        for(int i = 0; i < n; i++){
            int t, f;
            cin >> t >> f;
            drop(t, f);
            // for(int y = 99; y <= 101; y++){
            //     for(int x = 99; x <= 101; x++){
            //         cout << u[y][x];
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }
        init();
        for(int i = 1; i <= 6; i++){
            cout << ans[i];
            if(i == 6)cout << endl;
            else cout << " ";
        }
    }

    return 0;
}