#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll len(ll x1, ll y1, ll x2, ll y2){
    return abs(x1 - x2) + abs(y1 - y2);
}
ll calc(ll h, ll cx, ll cy, ll x, ll y){
    return max(h - len(cx, cy, x, y), 0LL);
}

int main(){

    ll N;
    cin >> N;
    vector<ll>X(N), Y(N), H(N);
    ll idx = 0;
    for(ll i = 0; i < N; i++){
        cin >> X[i] >> Y[i] >> H[i];
        if(H[i] > 0)idx = i;
    }
    for(ll cx = 0; cx <= 100; cx++){
        for(ll cy = 0; cy <= 100; cy++){
            ll h = H[idx] + len(cx, cy, X[idx], Y[idx]);
            ll flg = 1;
            for(ll i = 0; i < N; i++){
                if(calc(h, cx, cy, X[i], Y[i]) != H[i]){
                    flg = 0;
                    break;
                }
            }
            if(flg){
                cout << cx << " " << cy << " " << h << endl;
                return 0;
            }
        }
    }

    return 0;
}