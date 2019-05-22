#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int mp[12][12];
int imos[10][12][12];

int get(int t, int x1, int y1, int x2, int y2){
    return imos[t][y2][x2] - imos[t][y2][x1 - 1] - imos[t][y1 - 1][x2] + imos[t][y1 - 1][x1 - 1];
}

int getMin(int x1, int y1, int x2, int y2){
    for(int i = 0; ;i++){
        if(get(i, x1, y1, x2, y2))return i;
    }
}
int getMax(int x1, int y1, int x2, int y2){
    for(int i = 9; ;i--){
        if(get(i, x1, y1, x2, y2))return i;
    }
}

int getMinEdge(int x1, int y1, int x2, int y2){
    int mn = getMin(x1, y1, x2, y1);
    mn = min(mn, getMin(x1, y2, x2, y2));
    mn = min(mn, getMin(x1, y1, x1, y2));
    mn = min(mn, getMin(x2, y1, x2, y2));
    return mn;
}

int main(){

    for(int d, w; cin >> d >> w, d; ){
        int ans = 0;
        for(int y = 1; y <= d; y++){
            for(int x = 1; x <= w; x++){
                cin >> mp[y][x];
            }
        }
        for(int i = 0; i < 10; i++){
            for(int y = 0; y < 12; y++){
                for(int x = 0; x < 12; x++){
                    imos[i][y][x] = 0;
                }
            }
            for(int y = 1; y <= d; y++){
                for(int x = 1; x <= w; x++){
                    imos[i][y][x] = imos[i][y][x - 1];
                    if(mp[y][x] == i)imos[i][y][x]++;
                }
            }
            for(int x = 1; x <= w; x++){
                for(int y = 1; y <= d; y++){
                    imos[i][y][x] += imos[i][y - 1][x];
                }
            }
        }
        for(int y1 = 1; y1 <= d; y1++){
            for(int x1 = 1; x1 <= w; x1++){
                for(int y2 = y1 + 2; y2 <= d; y2++){
                    for(int x2 = x1 + 2; x2 <= w; x2++){
                        int flg = 1;
                        int tmp = 0;
                        int edge = getMinEdge(x1, y1, x2, y2);
                        for(int i = 0; i < 10; i++){
                            int cnt = get(i, x1+1, y1+1, x2-1,y2-1);
                            if(edge <= i && cnt)flg = 0;      
                            tmp += (edge - i) * cnt;
                        }
                        if(flg){
                            ans = max(ans, tmp);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}