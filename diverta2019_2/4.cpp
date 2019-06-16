#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N;
    ll r[3][2];
    cin >> N;
    for(ll i = 0; i < 2; i++){
        for(ll j = 0; j < 3; j++){
            cin >> r[j][i];
        }
    }
    vector<ll>ab(N + 1, -1);
    ab[0] = 0;
    for(ll i = 0; i < N; i++){
        if(ab[i] < 0)continue;
        for(ll j = 0; j < 3; j++){
            if(r[j][0] > r[j][1])continue;
            ll w = r[j][0];
            ll v = r[j][1];
            if(i + w > N)continue;
            ab[i + w] = max(ab[i + w], ab[i] + v);
        }
    }
    ll N2 = N;
    for(ll i = 0; i <= N; i++){
        if(ab[i] < 0)continue;
        N2 = max(N2, N - i + ab[i]);
    }
    vector<ll>ba(N2 + 1, -1);
    ba[0] = 0;
    for(ll i = 0; i < N2; i++){
        if(ba[i] < 0)continue;
        for(ll j = 0; j < 3; j++){
            if(r[j][1] > r[j][0])continue;
            ll w = r[j][1];
            ll v = r[j][0];
            if(i + w > N2)continue;
            ba[i + w] = max(ba[i + w], ba[i] + v);
        }
    }
    ll N3 = N2;
    for(ll i = 0; i <= N2; i++){
        if(ba[i] < 0)continue;
        N3 = max(N3, N2 - i + ba[i]);
    }
    cout << N3 << endl;

    return 0;
}