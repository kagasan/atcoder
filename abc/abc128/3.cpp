#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    int N, M;
    cin >> N >> M;
    int flg[11][11] = {};
    int p[11] = {};
    for(int i = 0; i < M; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int s;
            cin >> s;
            s--;
            flg[i][s] = 1;
        }
    }
    for(int i = 0; i < M; i++)cin >> p[i];
    int ans = 0;
    for(int i = 0; i < (1 << N); i++){
        int f = 1;
        for(int j = 0; j < M; j++){
            int cnt = 0;
            for(int k = 0; k < N; k++){
                if((i & (1 << k)) && flg[j][k])cnt++;
            }
            if(cnt % 2 != p[j]){
                f = 0;
            }
        }
        if(f)ans++;
    }
    cout << ans << endl;

    return 0;
}