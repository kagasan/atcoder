#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int flg[1010][5];

void solve(int A){
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 1010; x++){
            flg[x][y] = 0;
        }
    }
    for(int x = 2;;){
        if(flg[x-1][1] == 1 && flg[x-1][2] == 1 && flg[x-1][3] == 1 && x < A / 3){
            x++;
            continue;
        }
        cout << x << " " << 2 << endl << flush;
        int gx, gy;
        cin >> gx >> gy;
        if(gx == 0 && gy == 0)break;
        flg[gx][gy] = 1;
    }
}

int main(){

    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int A;
        cin >> A;
        solve(A);
    }

    return 0;
}
