#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll H, W;
    cin >> H >> W;
    ll A[30][30];
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++){
            cin >> A[y][x];
        }
    }
    ll ans = 1145141919;
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++){
            ll tmp = 0;
            for(ll y2 = 1; y2 <= H; y2++){
                for(ll x2 = 1; x2 <= W; x2++){
                    tmp += A[y2][x2] * min(abs(y - y2), abs(x - x2));
                }
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;

    return 0;    
}