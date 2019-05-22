#include "bits/stdc++.h"
using namespace std;

int h[220][220];
int up[220][220];
int init(){
    int cnt = 0;
    for(int i = 0; i < 220; i++){
        for(int j = 0; j < 220; j++){
            h[i][j] = 0;
            cnt += up[i][j];
            up[i][j] = 0;
        }
    }
    return cnt;
}

int dice[6];
// , 4
//1, 0, 2, 3
// , 5

void drop(int t, int f){
    dice[0] = t;
    dice[1] = f;
    
}

int main(){
    init();
    for(int n; cin >> n, n;){
        for(int i = 0; i < n; i++){
            int t, f;
            cin >> t >> f;
            drop(t, f);
        }
        cout << init() << endl;
    }

    return 0;
}