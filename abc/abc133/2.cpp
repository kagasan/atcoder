#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};



int main(){

    map<ll, ll>flg;
    for(ll i = 0; i < 5000; i++){
        flg[i * i] = 1;
    }

    ll N, D;
    cin >> N >> D;
    ll X[15][15];
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < D; j++){
            cin >> X[i][j];
        }
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        for(ll j = i + 1; j < N; j++){
            ll sum = 0;
            for(ll k = 0; k < D; k++){
                sum += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
            }
            if(flg[sum])ans++;
        }
    }
    cout << ans << endl;

    return 0;
}