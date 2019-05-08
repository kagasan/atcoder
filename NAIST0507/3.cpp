#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    for(int R, N; cin >> R >> N, R;){
        map<int, int>H;
        for(int i = 0; i < N; i++){
            int l, r, h;
            cin >> l >> r >> h;
            for(int x = l; x < r; x++){
                H[x] = max(H[x], h);
            }
        }
        double ans = 1234567;
        for(int X = -R; X < R; X++){
            int x = X;
            if(X < 0)x = X + 1;
            double h = sqrt(R * R - x * x);
            ans = min(ans, H[X] + (R - h));
        }
        printf("%.10f\n", ans);
    }

    return 0;
}