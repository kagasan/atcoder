#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, M;
    cin >> N >> M;
    vector<ll>L(M), R(M);
    for(int i = 0; i < M; i++)cin >> L[i] >> R[i];
    ll l = L[0], r = R[0];
    for(ll i = 1; i < M; i++){
        if(r < L[i] || R[i] < l){
            cout << 0 << endl;
            return 0;
        }
        l = max(l, L[i]);
        r = min(r, R[i]);
    }
    cout << r - l + 1 << endl;

    return 0;
}