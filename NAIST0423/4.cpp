#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

double tkt[8];
double flg[256][30];
double path[30][30];

int main(){

    for(int n, m, p, a, b; cin >> n >> m >> p >> a >> b;){
        a--;
        b--;
        if(n == 0)break;
        for(int i = 0; i < 256; i++){
            for(int j = 0; j < 30; j++){
                flg[i][j] = 1234;
            }
        }
        for(int i = 0; i < 30; i++){
            for(int j = 0; j < 30; j++){
                path[i][j] = 1234;
            }
        }
        for(int i = 0; i < n; i++)cin >> tkt[i];
        for(int i = 0; i < p; i++){
            int x, y, z;
            cin >> x >> y >> z;
            x--;
            y--;
            path[x][y] = z;
            path[y][x] = z;
        }
        flg[0][a] = 0.0;
        for(int bit = 0; bit < (1 << n); bit++){
            for(int f = 0; f < m; f++){
                double cs = flg[bit][f];
                if(cs > 1000)continue;
                for(int t = 0; t < m; t++){
                    if(path[f][t] > 1000)continue;
                    for(int b = 1, j = 0; j < n; b <<= 1, j++){
                       if(bit & b)continue;
                        flg[bit + b][t] = min(flg[bit + b][t], cs + path[f][t] / tkt[j]);
                    }
                }
            }
        }
        double ans = 1234;
        for(int i = 0; i < (1 << n); i++){
            ans = min(ans, flg[i][b]);
        }
        if(ans > 1000){
            printf("Impossible\n");
        }
        else{
            printf("%.9f\n", ans);
        }
    }

    return 0;
}