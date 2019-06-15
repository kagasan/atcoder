#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll imos[501][501] = {};
    ll N, M, Q;
    cin >> N >> M >> Q;
    for(ll i = 0; i < M; i++){
        ll l, r;
        cin >> l >> r;
        imos[l][r]++;
    }
    for(ll y = 1; y <= 500; y++){
        for(ll x = 1; x <= 500; x++){
            imos[y][x] += imos[y][x - 1];
        }
    }
    for(ll x = 1; x <= 500; x++){
        for(ll y = 1; y <= 500; y++){
            imos[y][x] += imos[y - 1][x];
        }
    }
    for(ll i = 0; i < Q; i++){
        ll p, q;
        cin >> p >> q;
        cout << imos[q][q] - imos[p - 1][q] - imos[q][p - 1] + imos[p - 1][p - 1] << endl;
    }

    return 0;
}
