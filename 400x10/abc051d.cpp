#include "bits/stdc++.h"
using namespace std;

int N, M;
int path[100][100];
int cost[100][100];

void init(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            path[i][j] = 200000;
            cost[i][j] = 200000;
        }
    }
}

int main(){

    init();

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        path[a][b] = c;
        path[b][a] = c;
        cost[a][b] = c;
        cost[b][a] = c;
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            if(path[i][j] == 200000)continue;
            if(path[i][j] > cost[i][j])ans++;
        }
    }
    cout << ans << endl;

    return 0;
}