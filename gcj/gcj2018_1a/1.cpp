#include "bits/stdc++.h"
using namespace std;
#define rep(i, x)
typedef long long ll;

void solve(int t){
    const string result[2] = {"IMPOSSIBLE", "POSSIBLE"};
    int flg = 1;
    int H, W, N, M;
    cin >> H >> W >> N >> M;
    int X[111] = {}, Y[111] = {};
    for(int i = 1; i < 111; i++)X[i] = W;
    for(int i = 1; i < 111; i++)Y[i] = H; 
    int XSUM[111] = {}, YSUM[111] = {};
    int waffle[111][111] = {};
    int sum = 0;
    for(int y = 1; y <= H; y++){
        for(int x = 1; x <= W; x++){
            char c;
            cin >> c;
            if(c == '@'){
                waffle[y][x]++;
                sum++;
                XSUM[x]++;
                YSUM[y]++;
            }
        }
    }

    for(int y = 1, i = 1; y <= H; y++){
        YSUM[y] += YSUM[y-1];
        if(YSUM[y] == i * sum / (N + 1)){
            Y[i] = y;
            i++;
        }
    }
    for(int x = 1, i = 1; x <= W; x++){
        XSUM[x] += XSUM[x-1];
        if(XSUM[x] == i * sum / (M + 1)){
            X[i] = x;
            i++;
        }
    }

    int ideal = sum / (N + 1) / (M + 1);
    if(ideal * (N + 1) * (M + 1) != sum)flg = 0;
    for(int n = 1; n <= N + 1; n++){
        for(int m = 1; m <= M + 1; m++){
            int cnt = 0;
            for(int y = Y[n-1] + 1; y <= Y[n]; y++){
                for(int x = X[m-1] + 1; x <= X[m]; x++){
                    if(waffle[y][x])cnt++;
                }
            }
            if(cnt != ideal)flg = 0;
        }
    }
    cout << "Case #" << t << ": " << result[flg] << endl;
}

int main(){

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        solve(t);
    }

    return 0;
}